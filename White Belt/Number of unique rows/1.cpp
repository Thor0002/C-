#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> set;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    set.insert(s);
  }
  cout << set.size() << endl;
  return 0;
}