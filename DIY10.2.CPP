#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream input("in.txt");
    if (!input) {
        cerr << "Could not open in.txt" << endl;
        return 1;
    }

    ofstream output("out.txt");
    if (!output) {
        cerr << "Could not open out.txt for writing" << endl;
        return 1;
    }

    string line;
    size_t lineNumber = 0;
    while (getline(input, line)) {
        output << ++lineNumber << ": " << line << '\n';
        if (!output) {
            cerr << "Could not write to out.txt" << endl;
            return 1;
        }
    }

    if (input.bad()) {
        cerr << "Error reading in.txt" << endl;
        return 1;
    }

    cout << "Copied " << lineNumber << " line(s) to out.txt" << endl;
    return 0;
}