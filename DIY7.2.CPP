#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string color;

public:
    explicit Shape(const string &shapeColor) : color(shapeColor) {
        cout << "Shape constructor" << endl;
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(const string &shapeColor, int sideCount)
        : Shape(shapeColor), sides(sideCount) {
        cout << "Polygon constructor" << endl;
    }
};

class Rectangle : public Polygon {
    double area;

public:
    Rectangle(const string &shapeColor, double rectangleLength,
              double rectangleWidth)
        : Polygon(shapeColor, 4),
          area(rectangleLength * rectangleWidth) {
        cout << "Rectangle constructor" << endl;
    }

    void showDetails() const {
        cout << "Color: " << color << endl;
        cout << "Sides: " << sides << endl;
        cout << "Area: " << area << endl;
    }
};

int main() {
    Rectangle rectangle("Blue", 8, 5);
    rectangle.showDetails();

    return 0;
}