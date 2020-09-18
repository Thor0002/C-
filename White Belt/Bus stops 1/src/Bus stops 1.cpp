#include <iostream>
#include <map>
#include <vector>
using namespace std;

void new_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
	int k;
	string s, name;
	cin >> name >> k;
	for(int i = 0; i < k; i++){
		cin >> s;
		buses[name].push_back(s);
		stops[s].push_back(name);
	}
}

void buses_for_stop(map<string, vector<string>>& stops) {
	string stop;
	cin >> stop;
	if (stops[stop].empty())
	{stops.erase(stop); cout << "No stop" << endl;}
	else {
	  for (const auto& bus : stops[stop]){
		  cout << bus + " " ;
	  }
	  cout << endl;
	}
}

void stops_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops){
	string bus;
	cin >> bus;
	if (buses[bus].empty())
	{buses.erase(bus); cout << "No bus" << endl;}
	else {
		for (const auto& stop : buses[bus]){
		  cout << "Stop " + stop + ":";
		  if (stops[stop].size() == 1)
		  {cout << " no interchange";}
		  else {
		    for (const auto& other_bus : stops[stop]){
		  	  if (other_bus != bus) {cout << " " + other_bus;}
	  	    }
		  }
		  cout << endl;
	    }
	}
}

void all_buses(map<string, vector<string>>& buses){
	if (buses.empty()) {cout << "No buses" << endl;}
	else {
		for(const auto& bus_stops : buses){
		cout << "Bus " + bus_stops.first + ":";
		for (const auto& stop : bus_stops.second){
			cout << " " + stop;
		}
		cout << endl;
	    }
	}
}

int main() {
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    int k;
    string s;
    cin >> k;
    for (int i = 0; i < k; i++){
    	cin >> s;
    	if (s == "NEW_BUS") {new_bus(buses, stops);}
    	else if (s == "BUSES_FOR_STOP") {buses_for_stop(stops);}
    	else if (s == "STOPS_FOR_BUS") {stops_for_bus(buses, stops);}
    	else if (s == "ALL_BUSES"){all_buses(buses);}
    }
	return 0;
}
