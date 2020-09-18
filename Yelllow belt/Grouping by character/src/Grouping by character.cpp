#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
	string s1({prefix});
	prefix++;
	string s2({prefix});
	auto it1 = lower_bound(range_begin, range_end, s1);
	auto it2 = lower_bound(range_begin, range_end, s2);
	return {it1, it2};

}

int main() {
  return 0;
}
