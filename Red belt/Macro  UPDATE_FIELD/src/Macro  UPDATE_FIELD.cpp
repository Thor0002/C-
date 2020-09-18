#include "airline_ticket.h"
#include "test_runner.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

#define UPDATE_FIELD(ticket, field, values) { \
    map<string, string>::const_iterator i = values.find(#field);  \
    if (i != values.end()) {                  \
	istringstream is(i->second);            \
	is >> ticket.field;                      \
    }                                        \
    }

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
		cerr << e.what() << endl;
		exit(1);
		return input_stream;
	}
}

istream& operator>>(istream& input_stream, Time& time){
	try{
    string s;
    input_stream >> s;
    stringstream stream(s);
    int hours, minutes;
    if (not (stream >> hours)){
    	throw runtime_error("Wrong time format: " + s);
    }
    if (stream.peek() != ':'){
    	throw runtime_error("Wrong time format: " + s);
    }
    stream.ignore(1);
    if (not (stream >> minutes)){
    	throw runtime_error("Wrong time format: " + s);
    }
    string e = "";
    stream >> e;
    if (e != "") {
    	throw runtime_error("Wrong time format: " + s);
    }
    if (hours < 0 or hours > 23){
        	throw runtime_error("Hours value is invalid: " + to_string(hours));
        }
    if (minutes < 0 or minutes > 59){
    	throw runtime_error("Minutes is invalid: " + to_string(minutes));
    }
    Time new_time = {hours, minutes};
    time = new_time;
    return input_stream;
	} catch(exception& e){
		cerr << e.what() << endl;
		exit(1);
		return input_stream;
	}
}

ostream& operator<<(ostream& stream,const Date& date){
	stream << setfill('0') << setw(4) << date.year << "-" << setw(2);
	stream << date.month << "-" << setw(2) << date.day << setfill(' ');
	return stream;
}

bool operator==(const Date& d1, const Date& d2){
	return d1.day == d2.day and d1.month == d2.month and d1.year == d2.year;
}

bool operator==(const Time& t1, const Time& t2){
	if (t1.hours == t2.hours and t1.minutes == t2.minutes) {return true;}
	return false;
}

ostream& operator<<(ostream& stream,const Time& t){
	stream << t.hours  << ":" << t.minutes;
	return stream;
}
/*
void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}

*/
