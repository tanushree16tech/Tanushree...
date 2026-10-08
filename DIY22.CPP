#include <iostream>
using namespace std;

int power(int base, int exp = 2) {
    int p = 1;

    for(int i = 1; i <= exp; i++)
        p *= base;

    return p;
}

int main() {
    cout << "power(5) = " << power(5) << endl;
    cout << "power(2,10) = " << power(2,10);
}