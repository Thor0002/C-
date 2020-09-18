#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,x;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	sort(begin(a),end(a),[](int a1, int a2){return (abs(a1) < abs(a2));});
	for (auto x : a){
		cout << x << " ";
	}
	return 0;
}
