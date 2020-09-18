#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <string>

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

bool IsPalindrom(const string& str) {
  // �� ������ ��������� ���� ��������� ���������� �������,
  // ����� ���������, ��� ���� ����� ���������� ���������� ���
  // � ����� ������������
}

void Test(){
	Assert(IsPalindrom(""), "empty string");
	Assert(IsPalindrom("a"), "a");
	Assert(IsPalindrom("f"), "f");
	Assert(IsPalindrom("k"), "k");
	Assert(IsPalindrom("z"), "z");
	Assert(IsPalindrom(" "), " ");
	Assert(IsPalindrom("_"), "_");
	Assert(IsPalindrom("-"), "-");
	Assert(IsPalindrom(",.,"), ",.,");
	Assert(IsPalindrom("aba aba"), "aba aba");
	Assert(!IsPalindrom("abc cbb"), "abc cbb");
	Assert(!IsPalindrom("aasfna"), "aasfna");
	Assert(IsPalindrom("aaa"), "aaa");
	Assert(IsPalindrom("aaaa"), "aaaa");
	Assert(!IsPalindrom("acaaaaa"), "acaaaaa");
	Assert(!IsPalindrom("aaaaaca"), "aaaaaca");
	Assert(!IsPalindrom("aaA"), "aaA");
	Assert(!IsPalindrom("Aaa"), "Aaa");
	Assert(IsPalindrom("A a_a A"), "A a_a A");
	Assert(IsPalindrom("121"), "121");
	Assert(!IsPalindrom("11121"), "11121");
	Assert(!IsPalindrom("12111"), "12111");
	Assert(!IsPalindrom("ab"), "ab");
	Assert(IsPalindrom("aa"), "aa");
	Assert(!IsPalindrom("Aa"), "Aa");
	Assert(!IsPalindrom("aA"), "aA");
	Assert(IsPalindrom("wasitacaroracatisaw"), "wasitacaroracatisaw");
	Assert(!IsPalindrom(" wasitacaroracatisaw"), " wasitacaroracatisaw");
	Assert(!IsPalindrom("wasitacaroracatisaw "), "wasitacaroracatisaw ");
	Assert(!IsPalindrom("was ita caro raca tisaw"), "was ita caro raca tisaw");
	Assert(!IsPalindrom("wasitacaXoracatisaw"), "wasitacaroracatisaw");
	Assert(!IsPalindrom("wasitacaroXacatisaw"), "wasitacaroracatisaw");


}

int main() {
  TestRunner runner;
  runner.RunTest(Test, "Test");
  // �������� ���� ���� �����
  return 0;
}
