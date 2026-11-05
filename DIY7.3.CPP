#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person(const string &personName, int personId)
        : name(personName), id(personId) {
        cout << "Person constructor" << endl;
    }

    void showPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Student : virtual public Person {
protected:
    string course;

public:
    Student(const string &personName, int personId, const string &studentCourse)
        : Person(personName, personId), course(studentCourse) {
        cout << "Student constructor" << endl;
    }
};

class Employee : virtual public Person {
protected:
    string department;

public:
    Employee(const string &personName, int personId,
             const string &employeeDepartment)
        : Person(personName, personId), department(employeeDepartment) {
        cout << "Employee constructor" << endl;
    }
};

class TA : public Student, public Employee {
    string subject;

public:
    TA(const string &personName, int personId, const string &studentCourse,
       const string &employeeDepartment, const string &teachingSubject)
        : Person(personName, personId),
          Student(personName, personId, studentCourse),
          Employee(personName, personId, employeeDepartment),
          subject(teachingSubject) {
        cout << "TA constructor" << endl;
    }

    void showDetails() const {
        showPerson();
        cout << "Course: " << course << endl;
        cout << "Department: " << department << endl;
        cout << "Teaching subject: " << subject << endl;
    }
};

int main() {
    TA assistant("Meera", 201, "Computer Science", "Engineering", "C++");
    cout << endl << "Teaching assistant details:" << endl;
    assistant.showDetails();

    return 0;
}