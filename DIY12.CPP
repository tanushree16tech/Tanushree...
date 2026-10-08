#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string a, b;

    cout << "Enter two words: ";
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a == b)
        cout << "They are anagrams";
    else
        cout << "They are not anagrams";
}