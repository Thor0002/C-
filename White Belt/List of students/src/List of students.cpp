#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	int N;
	vector<Student> a;
	cin >> N;
	string s;
	int x;
	for (int i = 0; i < N; i++){
		cin >> s;
		a.push_back({s});
		cin >> s;
		//cout << a[0].name;
		a[i].surname = s;
		//cout << a[0].surname;
		cin >> x;
		a[i].day = x;
		cin >> x;
	    a[i].month = x;
	    cin >> x;
	    a[i].year = x;
	}
    int M;
    cin >> M;
    for(int i = 1; i <= M; i++){
    	cin >> s;
    	cin >> x;
    	x--;
    	if (x < N & x >= 0) {
    		 if (s == "name") {
    		    	cout << a[x].name << " " << a[x].surname << endl;
    		 } else if (s == "date") {
    		    	cout << a[x].day << "." << a[x].month << "." << a[x].year << endl;
    		 } else {
    			 cout << "bad request" << endl;
    		 };

    	} else {
    		cout << "bad request" << endl;
    	}
    }
	return 0;
}





