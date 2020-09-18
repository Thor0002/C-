#include <iostream>
#include <sstream>
#include "phone_number.h"
using namespace std;

string int_to_str(int n){
	stringstream ss;
	string s;
	ss << n;
	ss >> s;
	return s;
}

PhoneNumber::PhoneNumber(const string &international_number){
	stringstream ss(international_number);
	int code;
	if (ss.peek() != '+'){
			throw invalid_argument("");
	}
	if (not (ss >> code)){
		throw invalid_argument("");
	}
	country_code_ = int_to_str(code);
	if (ss.peek() != '-'){
		throw invalid_argument("");
	}
	ss.ignore(1);
	if (not (ss >> code)){
		throw invalid_argument("");
	}
	city_code_ = int_to_str(code);
	if (ss.peek() != '-'){
		throw invalid_argument("");
	}
	ss.ignore(1);
	if (not (ss >> local_number_)){
		throw invalid_argument("");
	}

}

string PhoneNumber::GetCountryCode() const{
	return country_code_;
}

string PhoneNumber::GetCityCode() const{
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const{
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const{
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
/*
int main() {
	PhoneNumber n("+7-1233-");
	cout << n.GetInternationalNumber();
	return 0;
}
*/
