#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	os << r.buses_for_stop;
	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	os << r.stops_for_buses;
	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	os << r.allbuses;
	return os;
}
