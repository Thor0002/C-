#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> Alphabet(const string& word) {
  map<char, int> A;
  for (char c : word) {
    A[c]++;
  }
  return A;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    if (Alphabet(s1) == Alphabet(s2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}