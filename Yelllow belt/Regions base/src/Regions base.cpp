#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

tuple<string, string, map<Lang, string>, int64_t> Region_to_tuple(const Region& r){
	tuple<string, string, map<Lang, string>, int64_t> t(r.std_name, r.parent_std_name, r.names, r.population);
	return t;
}

int FindMaxRepetitionCount(const vector<Region>& regions){
	map<tuple<string, string, map<Lang, string>, int64_t>, int> d;
	int m = 0;
	for(const auto& region : regions){
		auto region_t = Region_to_tuple(region);
		m = max(m, ++d[region_t]);
	}
	return m;
}

int main() {
  return 0;
}

/*
bool operator<(const Region& lhs, const Region& rhs) {
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
  int result = 0;
  map<Region, int> repetition_count;
  for (const Region& region : regions) {
    result = max(result, ++repetition_count[region]);
  }
  return result;
}
*/
