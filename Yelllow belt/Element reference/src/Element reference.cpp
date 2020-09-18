#include <iostream>
#include <map>
using namespace std;

template <class Key, class Value>
Value& GetRefStrict(map<Key, Value>& d, Key k){
	if (d.count(k) == 1) {return d[k];}
	else {throw runtime_error("");}
}

int main() {
	return 0;
}
