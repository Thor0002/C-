#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	auto l = range_end - range_begin;
	if (l < 2) {return;}
	else {
		vector<typename RandomIt::value_type> v(range_begin, range_end);
		l /= 3;
		auto it1 = begin(v) + l;
		auto it2 = it1 + l;
		MergeSort(begin(v), it1);
		MergeSort(it1, it2);
		MergeSort(it2, end(v));
		vector<typename RandomIt::value_type> t_v;
		merge(begin(v), it1, it1, it2, back_inserter(t_v));
		merge(begin(t_v), end(t_v), it2, end(v), range_begin);
	}
}

int main() {
  return 0;
}




