#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
	if (v.size() > 1) {
	for(int i = 0; i <= (v.size()/2) - 1; i++) {
		int a = v[i];
		v[i] = v[v.size()-1-i];
		v[v.size()-1-i] = a;
	}
	}
}

int main() {
	return 0;
}
