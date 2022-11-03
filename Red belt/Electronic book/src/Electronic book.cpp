#include <iomanip>
#include <iostream>
#include <map>
//#include <utility>
//#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

class ReadingManager {
public:
  void Read(int user_id, int page_count) {
	  auto it_page = person_to_page.find(user_id);
	  if (it_page == person_to_page.end()){
		  auto it = upper_bound(pages.begin(), pages.end(), page_count);
		  pages.insert(it, page_count);
		  person_to_page[user_id] = page_count;
		  return;
	  }
	  auto it1 = upper_bound(pages.begin(), pages.end(), it_page->second);
	  auto it2 = lower_bound(pages.begin(), pages.end(), page_count);
	  int l1 = it1 - pages.begin(),
		  l2 = it2 - pages.begin();
	  l1--;l2--;
	  it_page->second = page_count;
      for(int i = l1; i < l2;i++){
    	  pages[i] = pages[i+1];
      }
      pages[l2] = page_count;
	  return;
  }

  double Cheer(int user_id) const {
	  auto it_page = person_to_page.find(user_id);
	  if (it_page == person_to_page.end()){return 0;}
	  if (person_to_page.size() == 1) {return 1;}
	  auto it = lower_bound(pages.begin(), pages.end(), it_page->second);
	  double count_less = (double) (it - pages.begin());
	  //cout << it_page->second << endl;
	  return (count_less / (person_to_page.size() - 1));
  }

  void print(){
	  cout << "person_to_page" << endl;
	  for(auto x : person_to_page){
		  cout << x.first << " " << x.second << endl;
	  }
	  cout << "pages" << endl;
	  for(auto x : pages){
		  cout << x << " ";
	  }
	  cout << endl;
  }

private:

  vector<int> pages;
  map<int, int> person_to_page;

};


int main() {
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);

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
//    manager.print();
//    cout << endl;
  }

  return 0;
}
