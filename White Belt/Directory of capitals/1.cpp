#include <iostream>
#include <string>
#include <map>

using namespace std;

void Change(map<string, string>& d,string c, string new_cap){
	if (d.count(c) == 0) {
        cout << "Introduce new country " << c << " with capital " << new_cap << endl;
      } else {
        const string& old_cap = d[c];
        if (old_cap == new_cap) {
          cout << "Country " << c << " hasn't changed its capital" << endl;
        } else {
          cout << "Country " << c << " has changed its capital from " << old_cap << " to " << new_cap << endl;
        }
      }
      d[c] = new_cap;
}

void  Rename(map<string, string>& d,string old_name, string new_name){
	 if (old_name == new_name || d.count(old_name) == 0 || d.count(new_name) == 1) {
        cout << "Incorrect rename, skip" << endl;
      } else {
        cout << "Country " << old_name << " with capital " << d[old_name] <<
            " has been renamed to " << new_name << endl;
        d[new_name] = d[old_name];
        d.erase(old_name);
      }
} 

void About(map<string, string>& d, string c) {
	if (d.count(c) == 0) {
        cout << "Country " << c << " doesn't exist" << endl;
      } else {
        cout << "Country " << c << " has capital " << d[c] << endl;
      }
}

void Dump(map<string, string>& d){
	if (d.size() == 0) {
        cout << "There are no countries in the world" << endl;
      } else {
        for (const auto& c_cap : d) {
          cout << c_cap.first << "/" << c_cap.second << " ";
        }
        cout << endl;
      }
}

int main() {
  int k;
  cin >> k;
  map<string, string> d;
  for (int i = 0; i < k; ++i) {
    string s;
    cin >> s;
    if (s == "CHANGE_CAPITAL") {
      string c, new_cap;
      cin >> c >> new_cap;
      Change(d, c, new_cap);
    } else if (s == "RENAME") {
      string old_name, new_name;
      cin >> old_name >> new_name;
	  Rename(d, old_name, new_name);
    } else if (s == "ABOUT") {
      string c;
      cin >> c;
	  About(d, c); 
    } else if (s == "DUMP") {
      Dump(d);
    }
  }
  return 0;
}
