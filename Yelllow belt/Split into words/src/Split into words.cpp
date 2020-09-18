#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> SplitIntoWords(const string& s){
	vector<string> v;
	auto it = begin(s);
	while(it != end(s)){
		auto new_it = find(it,end(s),' ');
		v.push_back(string(it, new_it));
		it = new_it;
		if (it != end(s)){it++;}
	}
	return v;

}

int main() {
}
