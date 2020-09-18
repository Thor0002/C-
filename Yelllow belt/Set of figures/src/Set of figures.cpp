#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Figure{
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;
};

class Rect : public Figure {
public:
	Rect(const int& w, const int& h) : Width(w), Height(h){}
	string Name() override {return "RECT";}
	double Perimeter() override {return (double) 2 * (Width + Height);}
	double Area() override {return (double) Width * Height;}
//private:
	int Width, Height;
};


class Triangle : public Figure {
public:
	Triangle(const int& x1, const int& x2, const int& x3) : a(x1), b(x2), c(x3){}
	string Name() override {return "TRIANGLE";}
	double Perimeter() override {return (double) (a + b + c);}
	double Area() override {
		double p = (a + b + c)/ (double) 2;
		return sqrt(p * (p-a) * (p - b) * (p - c));
	}
//private:
	int a, b, c;
};

const double pi = 3.14;

class Circle : public Figure {
public:
	Circle(const int& r) : R(r){}
	string Name() override {return "CIRCLE";}
	double Perimeter() override {return (double) 2 * pi * (double) R;}
	double Area() override {return (double) (R * R) * pi;}
//private:
	int R;
};

shared_ptr<Figure> CreateFigure(istream& s){
	string figure;
	s >> figure;
	shared_ptr<Figure> f;
	if (figure == "RECT"){
		int w, h;
		s >> w >> h;
		f = make_shared<Rect>(w, h);
	}
	if (figure == "TRIANGLE"){
		int a, b, c;
		s >> a >> b >> c;
		f = make_shared<Triangle>(a, b, c);
	}
	if (figure == "CIRCLE"){
		int r;
		s >> r;
		f = make_shared<Circle>(r);
	}
	return f;
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
