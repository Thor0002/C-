#include <iostream>
#include <vector>
using namespace std;

int& f(vector<int>& v){
	return v[2];
}

int main() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	f(v) = 2;
	cout << v.size() << endl;
	cout << v[2];
	return 0;
}
