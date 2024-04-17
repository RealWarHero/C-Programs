#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& name) : name(name) {}
    virtual void display() const {
        cout<<"Name : "<<name<<endl;
    }
};

class Student : public Person {
private:
    string course;
    int marks;
    int year;

public:
    Student(const string& name, const string& course, int marks, int year)
        : Person(name), course(course), marks(marks), year(year) {}

    void display() const override {
        Person::display();
        cout<<"Course : "<<course<<endl;
        cout<<"Marks : "<<marks<<endl;
        cout<<"Year : "<<year<<endl;
    }
};

class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(const string& name, const string& department, double salary)
        : Person(name), department(department), salary(salary) {}

    void display() const override {
        Person::display();
        cout<<"Department : "<<department<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

void showInfo(const Person& person) {
    person.display();
}

int main() {
    Person p1("Anand Saxena");
    Student s1("Khushi", "Computer Science", 85, 2027);
    Employee e1("Ronak", "DevOps", 50000);

    showInfo(p1);
    cout<<"\n";
    showInfo(s1);
    cout<<"\n";
    showInfo(e1);
    return 0;
}