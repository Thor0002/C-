#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class RouteManager {
public:
  void AddRoute(int start, int finish) {
	  routes[start].insert(finish); // Log Q
	  routes[finish].insert(start); // Log Q
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (routes.count(start) == 0) { // Log Q
        return result;
    }
    const set<int>& sts = routes.at(start); // sts = reachable stations
    auto it = sts.lower_bound(finish);     // Log G
    if (it != end(sts) and it != begin(sts)) {
    	result = min(result, *it - finish);
    	it--;
    	result = min(result, finish - *it);
    } else if (it != begin(sts)){
    	it--;
    	result = min(result, finish - *it);
    } else {
    	result = min(result, *it - finish);
    }
    return result;
  }
private:
  map<int, set<int>> routes;
};


int main() { // Q * Log Q
  RouteManager routes;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}
