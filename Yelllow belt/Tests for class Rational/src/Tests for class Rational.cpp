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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational(){};
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void Test(){
	Rational r;
	AssertEqual(r.Numerator(), 0, "m/n : 0/1 -> m = 0");
	AssertEqual(r.Denominator(), 1, "m/n : 0/1 -> n = 1");

	r = Rational(1,2);
	AssertEqual(r.Numerator(), 1, "m/n : 1/2 -> m = 1");
	AssertEqual(r.Denominator(), 2, "m/n : 1/2 -> n = 2");

	r = Rational(2,4);
	AssertEqual(r.Numerator(), 1, "m/n : 2/4 -> m = 1");
	AssertEqual(r.Denominator(), 2, "m/n : 2/4 -> n = 2");

	r = Rational(17,-34);
	AssertEqual(r.Numerator(), -1, "m/n : 17/-34 -> m = -1");
	AssertEqual(r.Denominator(), 2, "m/n : 17/-34 -> n = 2");

	r = Rational(-13,26);
	AssertEqual(r.Numerator(), -1, "m/n : -13/26 -> m = -1");
	AssertEqual(r.Denominator(), 2, "m/n : -13/26 -> n = 2");

	r = Rational(-7,-14);
	AssertEqual(r.Numerator(), 1, "m/n : -7/-14 -> m = -1");
	AssertEqual(r.Denominator(), 2, "m/n : -7/-14 -> n = -2");

	r = Rational(0, 1);
	AssertEqual(r.Numerator(), 0, "m/n : 0/1 -> m = 0");
	AssertEqual(r.Denominator(), 1, "m/n : 0/1 -> n = 1");

	r = Rational(0, 15);
	AssertEqual(r.Numerator(), 0, "m/n : 0/15 -> m = 0");
	AssertEqual(r.Denominator(), 1, "m/n : 0/15 -> n = 1");
}

int main() {
  TestRunner runner;
  runner.RunTest(Test, "Test");
  // добавьте сюда свои тесты
  return 0;
}
