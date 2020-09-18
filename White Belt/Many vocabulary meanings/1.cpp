#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> s;
  for (const auto& item : m) {
    s.insert(item.second);
  }
  return s;
}

int main() {
  return 0;
}