#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
	auto it = find_if(begin(elements), end(elements), [border](T e){return e > border;});
	return {it, end(elements)};
}

int main() {
}
