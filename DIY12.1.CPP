#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, int>> entries = {
        {"Asha", 85},
        {"Ravi", 72},
        {"Meera", 95},
        {"Kiran", 80}
    };

    sort(entries.begin(), entries.end(),
         [](const pair<string, int> &first, const pair<string, int> &second) {
             return first.second < second.second;
         });

    cout << "Sorted by value:" << endl;
    for (const auto &entry : entries)
        cout << entry.first << " " << entry.second << endl;

    return 0;
}