#include <algorithm>
#include <string>

using namespace std;

class ReversibleString {
public:
  ReversibleString() {}
  ReversibleString(const string& new_s) {
    s = new_s;
  }
  void Reverse() {
    reverse(begin(s), end(s));
  }
  string ToString() const {
    return s;
  }
private:
  string s;
};

int main() {
	return 0;
}