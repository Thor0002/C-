#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons){
	auto it1 = partition(begin(persons), end(persons), [](Person p){return p.gender == Gender::FEMALE;});
	auto it2 = partition(begin(persons), it1, [](Person p){return p.is_employed == 1;});
	auto it3 = partition(it1, end(persons), [](Person p){return p.is_employed == 1;});
	cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
	cout << "Median age for females = " << ComputeMedianAge(begin(persons), it1) << endl;
	cout << "Median age for males = " << ComputeMedianAge(it1, end(persons)) << endl;
	cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), it2) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(it2, it1) << endl;
	cout << "Median age for employed males = " << ComputeMedianAge(it1, it3) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(it3, end(persons)) << endl;
}

int main() {
  return 0;
}
