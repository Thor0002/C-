#include "test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES(out, x, y) (out) << (x) << endl << (y) << endl

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    //output << 6 << (5) << endl; output << ("red belt") << endl;
    PRINT_VALUES(output << 6, 5, "red belt");
    ASSERT_EQUAL(output.str(), "65\nred belt\n");
  }, "PRINT_VALUES usage example");
}

