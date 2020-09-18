#include <algorithm>
#include <vector>
using namespace std;

class FunctionPart {
public:
  FunctionPart(char new_op, double new_value_1) {
    op = new_op;
    value_1 = new_value_1;
  }
  double Apply(double value_2) const {
    if (op == '+') {
      return value_2 + value_1;
    } else if (op == '-') {  
      return value_2 - value_1;
    } else if (op == '/') {
	  return value_2 / value_1;
	} else {
	  return value_2 * value_1;
	}
  }
  void Invert() {
    if (op == '+') {
      op = '-';
    } else if (op == '-') { 
      op = '+';
    } else if (op == '*') { 
      op = '/';
    } else {
      op = '*';
	}
  }
private:
  char op;
  double value_1;
};

class Function {
public:
  void AddPart(char op, double value_1) {
    parts.push_back({op, value_1});
  }
  double Apply(double value) const {
    for (const FunctionPart& part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for (FunctionPart& part : parts) {
      part.Invert();
    }
    reverse(begin(parts), end(parts));
  }
private:
  vector<FunctionPart> parts;
};

int main(){
	return 0;
}