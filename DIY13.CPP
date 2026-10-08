#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s, word;
    vector<string> v;

    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    while(ss >> word)
        v.push_back(word);

    cout << "Reversed: ";
    for(int i = v.size()-1; i >= 0; i--)
        cout << v[i] << " ";
}