#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class Fst, class Snd> ostream& operator<<(ostream& stream, const pair<Fst, Snd> p);

template <class T> ostream& operator<<(ostream& stream, const vector<T>& s);

template <class T> ostream& operator << (ostream& stream, const set<T>& s);

template <class K, class V> ostream& operator << (ostream& stream, const map<K, V>& m);

//__________________________

template <class Fst, class Snd>
ostream& operator<<(ostream& stream, const pair<Fst, Snd> p){
	stream << "(" << p.first << "; " << p.second << ")";
	return stream;
}

template <class T>
ostream& operator<<(ostream& stream, const vector<T>& s) {
  stream << "[";
  bool t = true;
  for (const auto& x : s) {
    if (!t) {
        stream << ", ";
    }
    t = false;
    stream << x;
  }
  return stream << "]";
}

template <class T>
ostream& operator << (ostream& stream, const set<T>& s) {
  stream << "{";
  bool t = true;
  for (const auto& x : s) {
    if (!t) {
    	stream << ", ";
    }
    t = false;
    stream << x;
  }
  return stream << "}";
}

template <class K, class V>
ostream& operator << (ostream& stream, const map<K, V>& m) {
  stream << "{";
  bool t = true;
  for (const auto& kv : m) {
    if (!t) {
        stream << ", ";
    }
    t = false;
    stream << kv;
  }
  return stream << "}";
}

template<class Type1, class Type2>
void AssertEqual(const Type1& t1, const Type2& t2, const string& hint) {
  if (t1 != t2) {
    ostringstream ss;
    ss << "Assertion failed: " << t1 << " != " << t2 << " hint: " << hint;
    throw runtime_error(ss.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      fail_count++;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      fail_count++;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};


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


void Test(){
	Person p;
	AssertEqual(p.GetFullName(2000), "Incognito", "2000 Incognito");
	p.ChangeFirstName(2000, "A");
	AssertEqual(p.GetFullName(2000), "A with unknown last name", "2000 A with unknown last name");
	p.ChangeLastName(1999, "B");
	AssertEqual(p.GetFullName(1999), "B with unknown first name", "1999 B with unknown first name");
	AssertEqual(p.GetFullName(2000), "A B", "2000 A B");
	p.ChangeLastName(2002, "BB");
	AssertEqual(p.GetFullName(2001), "A B", "2001 A B");
	AssertEqual(p.GetFullName(2002), "A BB", "2002 A BB");
	p.ChangeLastName(1997, "b");
	AssertEqual(p.GetFullName(1997), "b with unknown first name", "1997 b with unknown first name");
	AssertEqual(p.GetFullName(1999), "B with unknown first name", "1999 B with unknown first name");
	AssertEqual(p.GetFullName(2000), "A B", "2000 A B");
	p.ChangeFirstName(1999, "a");
	AssertEqual(p.GetFullName(1999), "a B", "1999 a B");
	AssertEqual(p.GetFullName(1998), "b with unknown first name", "1998 b with unknown first name");
	AssertEqual(p.GetFullName(1996), "Incognito", "1996 Incognito");
	p.ChangeFirstName(1995, "aa");
	AssertEqual(p.GetFullName(1995), "aa with unknown last name", "1995 aa with unknown last name");
	AssertEqual(p.GetFullName(1994), "Incognito", "1994 Incognito");
	p.ChangeLastName(1993, "bb");
	AssertEqual(p.GetFullName(1994), "bb with unknown first name", "1994 bb with unknown first name");
}

int main() {
  TestRunner runner;
  runner.RunTest(Test, "Test");
  // добавьте сюда свои тесты
  return 0;
}
