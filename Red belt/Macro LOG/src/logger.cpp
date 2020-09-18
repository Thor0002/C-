#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

  void Log(const string& message){
	  os << message;
  }
  bool GetLine(){return log_line;}
  bool GetFile(){return log_file;}

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) \
  if (!logger.GetLine() and !logger.GetFile()){logger.Log(message + string("\n"));}                        \
  else if (!logger.GetLine()) {logger.Log(string(__FILE__) + " " + message + "\n");}               \
  else if (!logger.GetFile()) {logger.Log("Line " + to_string(__LINE__) + " " + message + "\n");}  \
  else {logger.Log(string(__FILE__) + ":" + to_string(__LINE__) + " " + message + "\n");}

void TestLog() {
/* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
 * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
 * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
 * � ��� ���� �������� ������. ��� ��������.
 *
 * ����� ����� ��������, �� ���������� ����������� ������ #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
 * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
 * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
 * ��� �� ��������� ����� ���*/

#line 1 "logger.cpp"

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:10 hello\n";
  expected += "Line 13 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestLog);
}

