#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
ostream& operator<<(ostream& s,const vector<T> v){
	for (const auto& x : v ){s << x << " ";}
	return s;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = n; i > 0; i--){v[n-i] = i;}
	do {
		cout << v << endl;
	} while(prev_permutation(v.begin(), v.end()));
	return 0;
}
