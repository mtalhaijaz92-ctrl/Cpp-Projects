#include <iostream>
#include <string>
using namespace std;


class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    virtual void showInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class Student : public Person
{
private:
    int rollNo;
    string program;

public:
    Student(string n, int a, int r, string p)
        : Person(n, a)
    {
        rollNo = r;
        program = p;
    }

    void showInfo() override
    {
        cout << "\n--- Student Information ---\n";
        Person::showInfo();

        cout << "Roll No: " << rollNo << endl;
        cout << "Program: " << program << endl;
    }
};


class Teacher : public Person
{
private:
    int teacherId;
    string subject;

public:
    Teacher(string n, int a, int id, string s)
        : Person(n, a)
    {
        teacherId = id;
        subject = s;
    }

    void showInfo() override
    {
        cout << "\n--- Teacher Information ---\n";
        Person::showInfo();

        cout << "Teacher ID: " << teacherId << endl;
        cout << "Subject: " << subject << endl;
    }
};


int main()
{
    Student s1("Ali Raza", 18, 1001, "ICS");

    Teacher t1("Ahmed Khan", 35, 501, "Computer Science");

    Person* p1 = &s1;
    Person* p2 = &t1;

    p1->showInfo();
    p2->showInfo();

    return 0;
}
