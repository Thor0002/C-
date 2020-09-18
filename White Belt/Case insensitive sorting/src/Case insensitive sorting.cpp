#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string s1, string s2){
	transform(begin(s1),end(s1),begin(s1),(int (*)(int))tolower);
	transform(begin(s2),end(s2),begin(s2),(int (*)(int))tolower);
	return (s1 < s2);
}

int main() {
	int n;
	string s;
	vector<string> a;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		a.push_back(s);
	}
	sort(begin(a),end(a),cmp);
	for (auto s : a){
		cout << s + " ";
	}
	return 0;
}
