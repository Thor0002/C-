#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

void add(map<string, set<string>>& dict){
	string w1, w2;
	cin >> w1 >> w2;
	dict[w1].insert(w2);
	dict[w2].insert(w1);
}

void check(map<string, set<string>>& dict){
	string word1, word2;
	cin >> word1 >> word2;
	if (dict[word1].find(word2) != end(dict[word1]) )
	{cout << "YES" <<endl;}
	else
	{cout << "NO" << endl;}
}

int main() {
	int k;
	string s, word;
	map<string, set<string>> dict;
	cin >> k;
	set<int> M = {1, 2, 3};
	for(int i = 0; i < k; i++){
		cin >> s;
		if (s == "ADD"){add(dict);};
		if (s == "COUNT"){cin >> word; cout << dict[word].size() << endl;};
	    if (s == "CHECK"){check(dict);};
	}
	return 0;
}
