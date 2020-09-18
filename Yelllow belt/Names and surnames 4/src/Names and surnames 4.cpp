#include <iostream>
#include <map>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  surnames[year] = last_name;
  }

  string GetFullName(int year) {
	  string name = "", surname = "";
	  auto name_it = names.upper_bound(year);
	  auto surname_it = surnames.upper_bound(year);
	  if (name_it != begin(names)){name = (--name_it)->second;}
	  if (surname_it != begin(surnames)){surname = (--surname_it)->second;}
	  if ((name == "") and (surname == "")) {return "Incognito"; }
	  else if ((surname == "")) {return name + " with unknown last name";}
	  else if ((name == "")) {return  surname + " with unknown first name";}
	  else {return	 name + " " + surname;}

  }
private:
  map<int, string> names;
  map<int, string> surnames;
};

int main() {
  return 0;
}
