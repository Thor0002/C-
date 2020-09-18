#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	vector<char> v;
	string s;
	cin >> n;
	if (n != 0) {
	while(n != 1){
		v.push_back(48 + n % 2);
		n = n / 2;
	}
	v.push_back(49);
    reverse(begin(v), end(v));
    string s1(begin(v), end(v));
    s = s1;
	} else {
		s = "0";
	}
	cout << s;
	return 0;
}
