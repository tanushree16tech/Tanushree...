#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    ifstream input("nums.txt");
    if (!input) {
        cerr << "Could not open nums.txt" << endl;
        return 1;
    }

    long long value;
    long long sum = 0;
    long long minimum = numeric_limits<long long>::max();
    long long maximum = numeric_limits<long long>::min();
    size_t count = 0;

    while (input >> value) {
        if ((value > 0 && sum > numeric_limits<long long>::max() - value) ||
            (value < 0 && sum < numeric_limits<long long>::min() - value)) {
            cerr << "Sum of integers exceeds the supported range" << endl;
            return 1;
        }
        sum += value;
        if (value < minimum)
            minimum = value;
        if (value > maximum)
            maximum = value;
        ++count;
    }

    if (!input.eof()) {
        cerr << "nums.txt contains an invalid integer" << endl;
        return 1;
    }

    if (count == 0) {
        cerr << "nums.txt contains no integers" << endl;
        return 1;
    }

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}