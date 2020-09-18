#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  string operation_code;
  is >> operation_code;
  if (operation_code == "NEW_BUS"){
	  q.type = QueryType::NewBus;
	  string bus;
	  is >> q.bus;
	  int stop_count;
	  is >> stop_count;
	  q.stops.resize(stop_count);
	  for (auto& stop : q.stops) {
		  is >> stop;
	  }
  } else if (operation_code == "BUSES_FOR_STOP") {
	  q.type = QueryType::BusesForStop;
	  is >> q.stop;
   } else if (operation_code == "STOPS_FOR_BUS") {
	   q.type = QueryType::StopsForBus;
	   is >> q.bus;
   } else if (operation_code == "ALL_BUSES") {
	   q.type = QueryType::AllBuses;
   }
  return is;
}

struct BusesForStopResponse {
	string buses_for_stop;
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
	os << r.buses_for_stop;
	return os;


}

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
	os << r.stops_for_buses;
	return os;
}

struct AllBusesResponse {
	string allbuses;
  // Наполните полями эту структуру
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
	os << r.allbuses;
	return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
  // Реализуйте этот метод
	  buses_to_stops[bus] = stops;
	  for (const string& stop : stops) {
	      stops_to_buses[stop].push_back(bus);
	        }

  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
  // Реализуйте этот метод
	  stringstream ss;
	  if (stops_to_buses.count(stop) == 0) {
	      ss << "No stop";
      } else {
    	  for (const string& bus : stops_to_buses.at(stop)) {
    		  ss << bus << " ";
	      }
	  }
	  BusesForStopResponse x;
	  x.buses_for_stop = ss.str();
	  return x;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  stringstream ss;
  // Реализуйте этот метод
      if (buses_to_stops.count(bus) == 0) {
        ss << "No bus";
      } else {
        for (const string& stop : buses_to_stops.at(bus)) {
          ss << "Stop " << stop << ": ";
          if (stops_to_buses.at(stop).size() == 1) {
            ss << "no interchange";
          } else {
            for (const string& other_bus : stops_to_buses.at(stop)) {
              if (bus != other_bus) {
                ss << other_bus << " ";
              }
            }
          }
          ss << endl;
        }
      }
      StopsForBusResponse x;
      x.stops_for_buses = ss.str();
      return x;
  }

  AllBusesResponse GetAllBuses() const {
	  // Реализуйте этот метод
	  stringstream ss;
      if (buses_to_stops.empty()) {
        ss << "No buses";
      } else {
        for (const auto& bus_item : buses_to_stops) {
          ss << "Bus " << bus_item.first << ": ";
          for (const string& stop : bus_item.second) {
            ss << stop << " ";
          }
          ss << endl;
        }
      }
      AllBusesResponse x;
      x.allbuses = ss.str();
      return x;
  }
private:
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
