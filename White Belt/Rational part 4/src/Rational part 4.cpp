#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
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
	if (stream.peek() == '/'){
	stream.ignore(1);
	stream >> m;
	if(stream) {d = Rational(n,m);}
	}
	return stream;
}

ostream& operator<<(ostream& stream,const Rational& d){
	stream << d.Numerator();
	stream << "/";
	stream << d.Denominator();
	return stream;
}

// Реализуйте для класса Rational операторы << и >>

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
