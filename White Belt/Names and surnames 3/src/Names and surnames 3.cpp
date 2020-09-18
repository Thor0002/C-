#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person {
public:
  Person(const string& name, const string& surname, const int& year){
	  year_of_birth = year;
	  names[year_of_birth] = name;
	  surnames[year_of_birth] = surname;
	  //cout << "Done!";
  }
  void ChangeFirstName(int year, const string& first_name) {
	  if (year >= year_of_birth) {
	     names[year] = first_name;
	  }
  }
  void ChangeLastName(int year, const string& last_name) {
	  if (year >= year_of_birth) {
	     surnames[year] = last_name;
	  }
  }
  string GetFullName(int year) const {
	  if (year >= year_of_birth) {
	  string name = "", surname = "";
	  for (auto year_name : names){
		  if (year_name.first > year){
			  break;
		  } else {
			  name = year_name.second;
		  }
	  }
	  for (auto year_surname : surnames){
	  	  if (year_surname.first > year){
	  		  break;
	  	  } else {
	  		  surname = year_surname.second;
	  	  }
	  }
	  if ((name == "") and (surname == "")) {return "Incognito"; }
	  else if ((surname == "")) {return name + " with unknown last name";}
	  else if ((name == "")) {return  surname + " with unknown first name";}
	  else {return name + " " + surname;}
	  } else {return "No person";}
  }
  string GetFullNameWithHistory(int year) const {
	  if (year >= year_of_birth){
	  string name = "", surname = "";
	  string previous_names = "", previous_surnames = "";
	  for (auto year_name : names){
	  	  if (year_name.first > year){
	  		  break;
	  	   } else {
	  		   if (name != year_name.second){
	  			  name = year_name.second;
	  			  previous_names = ", " + name +  previous_names;
	  		   }
	  	   }
	  }
	  previous_names.erase(0,name.size()+4);
	  previous_names = "(" +  previous_names + ")";
	  for (auto year_surname : surnames){
	  	  	  if (year_surname.first > year){
	  	  		  break;
	  	  	   } else {
	  	  		   if (surname != year_surname.second){
	  	  			  surname = year_surname.second;
	  	  			  previous_surnames = ", " + surname + previous_surnames;
	  	  		   }
	  	  	   }
	  }
	  previous_surnames.erase(0,surname.size()+4);
	  previous_surnames = "(" +  previous_surnames + ")";
	  if ((name == "") and (surname == "")) {return "Incognito"; }
	  else if ((surname == ""))
	          {if (previous_names == "()") {return name + " with unknown last name";}
	           else {return name + " " + previous_names + " with unknown last name";}}
	  else if ((name == ""))
	          {if (previous_surnames == "()") {return surname + " with unknown first name";}
               else {return surname + " " + previous_surnames + " with unknown first name";}}
	  else {if ((previous_names == "()") and (previous_surnames == "()")) {return	 name + " " + surname;}
	        else if (previous_surnames == "()") {return name + " " + previous_names + " " + surname;}
	        else if (previous_names == "()") {return name + " " + surname + " " + previous_surnames;}
	        else {return name + " " + previous_names + " " + surname + " " + previous_surnames;} }
	  } else {return "No person";}
  }
private:
  map<int, string> names;
  map<int, string> surnames;
  int year_of_birth;
  // ��������� ����
};

int main() {
  return 0;
}
