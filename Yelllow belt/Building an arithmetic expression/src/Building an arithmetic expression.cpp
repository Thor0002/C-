#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int x, N;
	cin >> x;
	cin >> N;
	if (N == 0) {cout << x; return 0;}
	deque<string> dq;
	string l;
	dq.push_back(to_string(x));
	getline(cin, l);
	for(int i = 0; i < N; i++){
		getline(cin, l);
		dq.push_front("(");
		dq.push_back(") " + l);
	}
	for (const string& s : dq){cout << s;}
	return 0;
}
