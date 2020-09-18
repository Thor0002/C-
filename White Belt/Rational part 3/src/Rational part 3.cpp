#include <iostream>
#include <algorithm>
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
	return {d1.Numerator()*d2.Numerator(),
	        d1.Denominator()*d2.Denominator()};
}

Rational operator/(Rational d1, Rational d2){
	return Rational((d1.Numerator()*d2.Denominator()),(d1.Denominator()*d2.Numerator()));
}

// Реализуйте для класса Rational операторы * и /

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
