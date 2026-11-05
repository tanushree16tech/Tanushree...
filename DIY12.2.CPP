#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int count;
    cout << "Enter the number of values: ";
    if (!(cin >> count) || count < 0) {
        cerr << "Please enter a non-negative count" << endl;
        return 1;
    }

    priority_queue<int> largestValues;
    cout << "Enter " << count << " integers: ";
    for (int i = 0; i < count; ++i) {
        int value;
        if (!(cin >> value)) {
            cerr << "Invalid or incomplete integer input" << endl;
            return 1;
        }
        largestValues.push(value);
    }

    cout << "Top " << (count < 3 ? count : 3) << " values: ";
    const int limit = count < 3 ? count : 3;
    for (int i = 0; i < limit; ++i) {
        cout << largestValues.top() << " ";
        largestValues.pop();
    }
    cout << endl;

    return 0;
}