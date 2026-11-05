#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &employeeName, int employeeId)
        : name(employeeName), id(employeeId) {}

    void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(const string &employeeName, int employeeId, int size)
        : Employee(employeeName, employeeId), teamSize(size) {}

    void showDetails() const {
        cout << "Manager" << endl;
        Employee::showDetails();
        cout << "Team size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(const string &employeeName, int employeeId, const string &expertise)
        : Employee(employeeName, employeeId), skill(expertise) {}

    void showDetails() const {
        cout << "Engineer" << endl;
        Employee::showDetails();
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    Manager manager("Asha", 101, 6);
    Engineer engineer("Ravi", 102, "C++");

    manager.showDetails();
    cout << endl;
    engineer.showDetails();

    return 0;
}