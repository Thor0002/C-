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
		l /= 2;
		auto it = begin(v) + l;
		MergeSort(begin(v), it);
		MergeSort(it, end(v));
		merge(begin(v), it, it, end(v), range_begin);
	}
}
/*
int main() {
	return 0;
}
*/
