#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    const array<Student, 3> records = {{{"Asha", 91}, {"Ravi", 78}, {"Meera", 88}}};

    ofstream output("students.txt");
    if (!output) {
        cerr << "Could not open students.txt for writing" << endl;
        return 1;
    }

    for (const Student &student : records)
        output << student.name << " " << student.marks << '\n';
    output.close();
    if (!output) {
        cerr << "Could not write all student records" << endl;
        return 1;
    }

    array<Student, 3> students;
    ifstream input("students.txt");
    if (!input) {
        cerr << "Could not open students.txt for reading" << endl;
        return 1;
    }

    for (Student &student : students) {
        if (!(input >> student.name >> student.marks)) {
            cerr << "Invalid or incomplete student records" << endl;
            return 1;
        }
    }

    cout << "Student records:" << endl;
    for (const Student &student : students)
        cout << student.name << " " << student.marks << endl;

    const Student *topper = &students[0];
    for (const Student &student : students) {
        if (student.marks > topper->marks)
            topper = &student;
    }

    cout << "Topper: " << topper->name << " (" << topper->marks << ")"
         << endl;
    return 0;
}