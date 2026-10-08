#include <iostream>
using namespace std;

class Rectangle {
    int length, width;

public:
    void setLength(int l) {
        if(l > 0) length = l;
    }

    void setWidth(int w) {
        if(w > 0) width = w;
    }

    int area() {
        return length * width;
    }

    int perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r;
    r.setLength(5);
    r.setWidth(3);

    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter();
}