#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> w1;
	for (auto w : words) {
		string s = w;
		reverse(s.begin(),s.end());
		if ( (w.size() >= minLength) and (w == s) ) {
			w1.push_back(w);
		}
	}
	return w1;
}

int main() {
	return 0;
}
