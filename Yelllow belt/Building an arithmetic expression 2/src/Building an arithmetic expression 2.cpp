#include <iostream>
#include <deque>
#include <string>
using namespace std;

int priority(const char& op){
	if (op == '+' or op == '-') {return 0;}
	if (op == '*' or op == '/') {return 1;}
}

int main() {
	int x, N, p = 1;
	cin >> x;
	cin >> N;
	if (N == 0) {cout << x; return 0;}
	deque<string> dq;
	string l;
	dq.push_back(to_string(x));
	for(int i = 0; i < N; i++){
		string op;
		int y;
		cin >> op;
		cin >> y;
		if (priority(op[0]) > p) {dq.push_front("(");dq.push_back(")");}
		dq.push_back(" " + op + " " +  to_string(y));
		p = priority(op[0]);
	}
	for (const string& s : dq){cout << s;}
	return 0;
}
