#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int k, n, l;
	l = 0;
	string s;
	map<set<string>, int> buses;
	cin >> k;
	for (int i = 0; i < k; i++){
		cin >> n;
		set<string> stops;
		for (int j = 0; j < n; j++) {
			cin >> s;
			stops.insert(s);
		}
		if (buses[stops] == 0){
			l++;
			buses[stops] = l;
			cout << "New bus " << l << endl;
		} else {
			cout << "Already exists for " << buses[stops] << endl;
		}
	}
	return 0;
}
