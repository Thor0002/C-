#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
	auto it1 = lower_bound(range_begin, range_end, prefix);
	string s = prefix;
	++s[s.size()-1];
	auto it2 = lower_bound(range_begin, range_end, s);
	return {it1, it2};
}
