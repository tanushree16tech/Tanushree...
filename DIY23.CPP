#include <iostream>
using namespace std;

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int min(int a, int b, int c) {
    return min(min(a,b),c);
}

int main() {
    cout << "Minimum of 8, 5: " << min(8,5) << endl;
    cout << "Minimum of 8, 5, 3: " << min(8,5,3);
}