#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <class Fst, class Snd> pair<Fst, Snd> Sqr(pair<Fst, Snd> p);

template <class T> vector<T> Sqr(vector<T>& v);

template <class Key, class Value> map<Key, Value> Sqr(map<Key, Value>& d);

//____________________________________________

template <class T>
T Sqr(T x){return x * x;}

template <class Fst, class Snd>
pair<Fst, Snd> Sqr(pair<Fst, Snd> p){
	p.first = Sqr(p.first);
	p.second = Sqr(p.second);
	return p;
}

template <class T>
vector<T> Sqr(vector<T>& v){
	vector<T>& v1 = v;
	for (T& x : v1){x = Sqr(x);}
	return v;
}

template <class Key, class Value>
map<Key, Value> Sqr(map<Key, Value>& d){
	map<Key, Value> d1 = d;
	for(auto& [key, value] : d1){value = Sqr(value);}
	return d1;
}

template <class Fst, class Snd>
ostream& operator<<(ostream& out, pair<Fst, Snd> p){
	cout <<  "(" << p.first << ", " << p.second << ") ";
	return out;
};

template <class T>
ostream& operator<<(ostream& out, vector<T> v){
	for (T& x : v){out << x << " ";}
	return out;
}

template <class Key, class Value>
ostream& operator<<(ostream& out, map<Key, Value> d){
	for (auto& [key,value] : d){cout << "[" << key << ", " << value << "] "<< " ";}
	return out;
}

int main() {
	return 0;
}
