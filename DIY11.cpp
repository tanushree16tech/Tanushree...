#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s;
    int v = 0, c = 0;

    cout << "Enter a sentence: ";
    getline(cin, s);

    for(char x : s) {
        if(isalpha(x)) {
            if(string("aeiouAEIOU").find(x) != string::npos)
                v++;
            else
                c++;
        }
    }

    cout << "Vowels: " << v << endl;
    cout << "Consonants: " << c;
}