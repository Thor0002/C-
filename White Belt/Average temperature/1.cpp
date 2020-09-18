#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, t, S = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> t;
	v.push_back(t);
    S += t;
  }
  int Av = S / n;
  vector<int> ind;
  for (int i = 0; i < n; i++) {
    if (v[i] > Av) {
      ind.push_back(i);
    }
  }
  cout << ind.size() << endl;
  for (int i = 0; i < ind.size();  i++) {
    cout << ind[i] << " ";
  }
  return 0;
}