/*
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>
#include <numeric>
#include <vector>

using namespace std;

class ReadingManager {
public:
  void Read(int user_id, int page_count) {
	  auto it_page = person_to_page.find(user_id);
	  if (it_page == person_to_page.end()){
		  page_to_person[page_count]++; // Log Q
		  person_to_page[user_id] = page_count; // Log Q
		  return;
	  }
	  page_to_person[it_page->second]--;     // Log Q
	  it_page->second = page_count;
	  page_to_person[page_count]++; // Log Q
  }

  double Cheer(int user_id) const {
	  auto it_page = person_to_page.find(user_id);
	  if (it_page == person_to_page.end()){return 0;}
	  if (person_to_page.size() == 1) {return 1;}
	  int page = it_page->second;
	  auto end_p = page_to_person.lower_bound(page); // Log Q
	  int count_less = 0;
	  for(auto it = page_to_person.begin(); it != end_p; it++){ //Q
		  count_less += it->second;
	  }
	  return count_less * 1.0 / (person_to_page.size() - 1);
  }

private:

  map<int, int> page_to_person;
  map<int, int> person_to_page;

};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << endl;//"\n";
    }
  }

  return 0;
}
*/
