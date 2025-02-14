#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
      auto p = dict.insert(word);
      if(p.second){
    	  newWords++;
      }
    }
    return newWords;
  }

  vector<string> KnownWords() const{
    return {begin(dict), end(dict)};
  }
};

