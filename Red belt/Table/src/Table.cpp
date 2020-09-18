#include "test_runner.h"
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Table{
public:
	Table(const size_t& n,const size_t& m){
		Resize(n, m);
	}
	vector<T>& operator[](const size_t& i){return table[i];}
	const vector<T>& operator[](const size_t& i) const {return table.at(i);}
	void Resize(const size_t& n,const size_t& m){
		table.resize(n);
		if (m == 0) {table.clear(); return;}
		for(auto& row : table){
			row.resize(m);
		}
	}
	pair<size_t, size_t> Size() const {
		if (table.empty() or table.at(0).empty()) {
			return {0, 0};
		} else {
			return {table.size(), table.at(0).size()};
		}
	}
private:
	vector<vector<T>> table;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
