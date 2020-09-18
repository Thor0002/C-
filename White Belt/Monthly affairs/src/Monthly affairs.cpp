#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<string>& v){
	for (auto& x : v){
		cout << x + " ";
	}
	cout << endl;
}

void add(vector<vector<string>>& to_do_list,int x, string name){
	to_do_list[x-1].push_back(name);
	//printVector(to_do_list[x-1]);
}

void dump(vector<vector<string>>& to_do_list,int x){
	cout << to_do_list[x-1].size();
	for (auto& d : to_do_list[x-1]) {
		cout << " " + d;
	}
	cout << endl;
}

void next(vector<vector<string>>& to_do_list,int& month_number,vector<int>& months){
	int k = months[(month_number + 1) % 12];
	if (months[month_number] > k){
		for (int i = months[month_number]; i > k; i--){
			to_do_list[k-1].insert(end(to_do_list[k-1]), begin(to_do_list[i-1]), end(to_do_list[i-1]));
			to_do_list[i-1].clear();
		}
	}
	month_number = (month_number + 1) % 12;
}

int main() {
	int k, month_number = 0;
	vector<int> months = {31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> to_do_list(31);
	cin >> k;
	string s, name;
	int x;
	for (int i = 0; i < k; i++){
		cin >> s;
		if (s == "ADD") {cin >> x >> name;  add(to_do_list,x,name);}// cout << "!ADD!" << endl;}
		else if (s == "DUMP") {cin >> x; dump(to_do_list,x);}//cout << "!DUMP!" << endl;}
		else { next(to_do_list,month_number,months);}//cout << "!NEXT!" << endl;}
	}
	return 0;
}
