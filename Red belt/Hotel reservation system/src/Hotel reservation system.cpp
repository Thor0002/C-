#include <iostream>
using namespace std;

class SystemReservation{
public:
	void Book(int64_t time, string hotel_name,int client_id,int room_count){
		current_time = time;

	}

private:
	int64_t current_time;

};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
