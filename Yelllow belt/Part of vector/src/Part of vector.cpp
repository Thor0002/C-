#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers){
	auto it = find_if(begin(numbers), end(numbers), [](int n){return n < 0;});
	while(it != begin(numbers)){
		it--;
		cout << *it << " ";
	}
}

int main() {
  return 0;
}
