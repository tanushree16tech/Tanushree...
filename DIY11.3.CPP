#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> frequencies;
    string word;

    cout << "Enter words (Ctrl+Z then Enter to finish): ";
    while (cin >> word)
        ++frequencies[word];

    if (frequencies.empty()) {
        cerr << "No words were entered" << endl;
        return 1;
    }

    string mostFrequent;
    int highestFrequency = 0;

    cout << "Word frequencies:" << endl;
    for (const auto &entry : frequencies) {
        cout << entry.first << ": " << entry.second << endl;
        if (entry.second > highestFrequency) {
            mostFrequent = entry.first;
            highestFrequency = entry.second;
        }
    }

    cout << "Most frequent word: " << mostFrequent << " ("
         << highestFrequency << ")" << endl;
    return 0;
}