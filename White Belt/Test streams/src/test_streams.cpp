#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	double a;
	cout << fixed << setprecision(3);
    while(not input.eof()){
     input >> a;
     cout << a << endl;
    }
	return 0;
}
