#include <iostream>
#include <vector>
using namespace std;

void add(vector<int>& v,int n){
	for(int i = 0; i < n; i++){
		v.push_back(1);
	}
}

void pick_up(vector<int>& v, int n){
	for(int i = 0; i < n; i++){
		v.pop_back();
	}
}

void change(vector<int>& v, int k, bool t){
	if (t) {v[k] = -1;}
	else {v[k] = 1;}
}

int count(vector<int>& v){
	int k = 0;
	for (auto& a : v){
		if (a == -1) {k++;}
	}
	return k;
}

int main() {
	int k, x;
	vector<int> q;
	string s;
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> s;
		if (s == "WORRY_COUNT") {cout << count(q) << endl;}
		else {cin >> x;
		if (s == "WORRY")  {change(q,x,true);}
		else if (s == "QUIET")  {change(q,x,false);}
		else if (x > 0) {add(q,x);}
		else if (x < 0) {pick_up(q,abs(x));}
		}
	}
	return 0;
}
