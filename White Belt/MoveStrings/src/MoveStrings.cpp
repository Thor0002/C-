#include <iostream>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& v1, vector<string>& v2) {
	for (auto& x : v1){
		v2.push_back(x);
	}
	v1.clear();
}

int main() {
	return 0;
}
