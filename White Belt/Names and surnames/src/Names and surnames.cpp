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
	  //cout << "year = " << year << endl;
	  string name = "", surname = "";
	  for (auto year_name : names){
		  //cout << year_name.first <<" " +  year_name.second << endl;
		  if (year_name.first > year){
			  //cout << ">" << endl;
			  break;
		  } else {
			  //cout << "<" << endl;
			  name = year_name.second;
		  }
	  }
	  for (auto year_surname : surnames){
		  //cout << year_surname.first <<" " +  year_surname.second << endl;
	  	  if (year_surname.first > year){
	  		  //cout << ">" << endl;
	  		  break;
	  	  } else {
	  		  //cout << "<" << endl;
	  		  surname = year_surname.second;
	  	  }
	  }
	  if ((name == "") and (surname == "")) {return "Incognito"; }
	  else if ((surname == "")) {return name + " with unknown last name";}
	  else if ((name == "")) {return  surname + " with unknown first name";}
	  else {return	 name + " " + surname;}

  }
private:
  map<int, string> names;
  map<int, string> surnames;
  // приватные поля
};

int main() {
  Person p;
  p.ChangeLastName(2000, "Ivanov");
  cout << p.GetFullName(2000);
  return 0;
}
