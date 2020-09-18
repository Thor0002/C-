#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& name, const string& type) : Name(name), Type(type) {}
	virtual void Walk(const string& destination) {
	        cout << Type + ": " << Name << " walks to: " << destination << endl;
	    }
    string GetName() const {return Name;}
    string GetType() const {return Type;}
    string Type_Name() {return Type + ": " + Name;}
/*?*/virtual ~Person() = default;
protected:
	const string Name;
	const string Type;
};

class Student : public Person{
public:

    Student(const string& name,const string& favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << Type_Name() << " learns" << endl;
    }

    void Walk(const string& destination) {
    	Person::Walk(destination);
    	SingSong();
    }

    void SingSong() {
        cout << Type_Name() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person{
public:

    Teacher(const string& name,const string& subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << Type_Name() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};


class Policeman : public Person{
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Check(const Person& p) {
        cout << Type_Name() << " checks " <<  p.GetType() << ". " << p.GetType() << "'s name is: " << p.GetName() << endl;
    }
};

void VisitPlaces(Person& pr,const vector<string> places) {
    for (auto p : places) {
        pr.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
