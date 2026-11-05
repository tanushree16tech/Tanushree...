#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using namespace std;

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    double radius;

    explicit Circle(double value) : radius(value) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

struct Square : Shape {
    double side;

    explicit Square(double value) : side(value) {}

    double area() const override {
        return side * side;
    }
};

unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle")
        return make_unique<Circle>(2.0);
    if (kind == "square")
        return make_unique<Square>(3.0);
    throw invalid_argument("Unknown shape: " + kind);
}

int main() {
    try {
        unique_ptr<Shape> circle = makeShape("circle");
        unique_ptr<Shape> square = makeShape("square");
        cout << "area circle = " << circle->area()
             << ", area square = " << square->area() << endl;
    } catch (const invalid_argument &error) {
        cerr << error.what() << endl;
        return 1;
    }

    return 0;
}