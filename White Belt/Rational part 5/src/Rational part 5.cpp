#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
          // Реализуйте конструктор
    	if (new_numerator == 0){numerator = 0; denominator = 1;}
    	else if (new_denominator > 0) {
    		 int gcd;
    		 gcd = abs(__gcd(new_numerator, new_denominator));
    		 numerator = new_numerator / gcd;
    		 denominator = new_denominator / gcd;
    	} else {
    		 int n, m, gcd;
    		 n = - new_numerator;
    		 m = abs(new_denominator);
    		 gcd = abs(__gcd(n, m));
    		 numerator = n / gcd;
    		 denominator = m / gcd;
    	}
    }

    int Numerator() const {
        // Реализуйте этот метод
    	return numerator;
    }

    int Denominator() const {
        // Реализуйте этот метод
    	return denominator;
    }

private:
    // Добавьте поля
    int numerator;
    int denominator;
};

bool operator==(const Rational& d1, const Rational& d2){
	return (d1.Numerator() == d2.Numerator()) and (d1.Denominator() == d2.Denominator());
}

Rational operator*(Rational d1, Rational d2){
	return Rational (d1.Numerator()*d2.Numerator(),d1.Denominator()*d2.Denominator());
}

Rational operator/(Rational d1, Rational d2){
	return Rational (d1.Numerator()*d2.Denominator(),d1.Denominator()*d2.Numerator());
}

istream& operator>>(istream& stream, Rational& d){
	int n = 0, m = 0;
	stream >> n;
	stream.ignore(1);
	stream >> m;
	if(n != 0 and m != 0) {d = Rational(n,m);}
	return stream;
}

ostream& operator<<(ostream& stream,const Rational& d){
	stream << d.Numerator();
	stream << "/";
	stream << d.Denominator();
	return stream;
}

bool operator<(Rational d1, Rational d2){
	return (d1.Numerator()*d2.Denominator() < d2.Numerator()*d1.Denominator());
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        vector<Rational> a = {{1, 25}, {1, 2}, {3, 4}};
        if (v != a ) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
