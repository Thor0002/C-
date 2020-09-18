#pragma once
#include <iostream>
using namespace std;

struct BusesForStopResponse {
	string buses_for_stop;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	string stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	string allbuses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
