#include <iostream>
#include <exception>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
using namespace std;

class Date{
 public:
	Date(){};
	Date (int new_year, int new_month, int new_day){
		year = new_year;
		month = new_month;
		day = new_day;
	}
	int year;
	int month;
	int day;
};

istream& operator>>(istream& input_stream, Date& date){
	try{
    string s;
    input_stream >> s;
    stringstream stream(s);
	int year, month, day;
	if (not (stream >> year)){
		throw runtime_error("Wrong date format: " + s);
	}
	if (stream.peek() != '-'){
		throw runtime_error("Wrong date format: " + s);
	}
    stream.ignore(1);
    if (not (stream >> month)){
        throw runtime_error("Wrong date format: " + s);
    	}
    if (stream.peek() != '-'){
    	throw runtime_error("Wrong date format: " + s);
    }
    stream.ignore(1);
    if (not (stream >> day)){
    	throw runtime_error("Wrong date format: " + s);
    	}
    string e = "";
    stream >> e;
    if (e != "") {
    	throw runtime_error("Wrong date format: " + s);
    }
    if (month < 1 or month > 12){
        	throw runtime_error("Month value is invalid: " + to_string(month));
        }
    if (day < 1 or day > 31){
    	throw runtime_error("Day value is invalid: " + to_string(day));
    }
    Date new_date = {year, month, day};
    date = new_date;
    return input_stream;
	} catch(exception& e){
		cout << e.what() << endl;
		//cout << "change cin" << endl;
		input_stream.setstate(ios::failbit);
		return input_stream;
	}
}

ostream& operator<<(ostream& stream,const Date& date){
	stream << setfill('0') << setw(4) << date.year << "-" << setw(2);
	stream << date.month << "-" << setw(2) << date.day << setfill(' ');
	return stream;
}

bool operator<(const Date& date1, const Date& date2){
	if (date1.year < date2.year)       {return true;}
	else if (date1.year > date2.year)  {return false;}
	else if (date1.month < date2.month){return true;}
	else if (date1.month > date2.month){return false;}
	else if (date1.day < date2.day)    {return true;}
	else if (date1.day > date2.day)    {return false;}
	else {return false;}
}

class Database{
 public:
	Database(){}
	Database(map<Date, set<string>> new_data){
		data = new_data;
	}

	map<Date, set<string>> data;

void Add(){
	Date date;
	string s;
	if(cin >> date){
		cin >> s;
		data[date].insert(s);
	}
}

void Del(){
	Date date;
	string s;
	if(cin >> date){
		getline(cin, s);
		//cout <<"|" + s + "|" << endl;
		stringstream stream(s);
		s = "";
		stream >> s;
		//cout <<"|" + s + "|" << endl;
		if (s == "")                                            //!!!!!!!!!!!!!!!!
		   {cout << "Deleted " << data[date].size() << " events" << endl;
		       data.erase(date);}
		else {if (data.find(date) != end(data)){
			  	 if (data[date].find(s) != end(data[date])){
			   	    cout << "Deleted successfully" << endl;
			  	    data[date].erase(s);}
			  	 else {cout << "Event not found" << endl;}
		      } else {cout << "Event not found" << endl;}}
	}
}

void Find(){
	Date date;
	if (cin >> date){
		if (data.find(date) != end(data)){
		  for (const auto& event : data[date]){
			  cout << event << endl;
		  }
		}
	}
}

void Print(){
	for (const auto& date_events : data){
		for (const auto& event : date_events.second){
			cout << date_events.first << " " + event << endl;
		}
	}
}
};

//	Database Db1 = { { {{1,1,1}, {"event1", "event2"}} }  };
//	Db1.data[{1, 1, 2}] = {"event3"};
//  _
int main() {
  Database db;
  string command;
  while (cin >> command) {
    if(command == "Add")      {db.Add();}
    else if(command == "Del") {db.Del();}
    else if(command == "Find"){db.Find();}
    else if(command == "Print"){db.Print();}
    else {cout << "Unknown command: " + command << endl;
//        cout << "change cin" << endl;
          cin.setstate(ios::failbit);
         }
  }

  return 0;
}
