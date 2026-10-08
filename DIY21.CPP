#include <iostream>
using namespace std;

int volume(int a) {
    return a * a * a;
}

int volume(int l, int b, int h) {
    return l * b * h;
}

float volume(float r, float h) {
    return 3.14 * r * r * h;
}

int main() {
    cout << "Cube: " << volume(3) << endl;
    cout << "Cuboid: " << volume(2,3,4) << endl;
    cout << "Cylinder: " << volume(2.0f,5.0f);
}