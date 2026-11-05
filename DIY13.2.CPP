#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a rectangle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a triangle" << endl;
    }
};

unique_ptr<Shape> createShape(const string &name) {
    if (name == "circle")
        return make_unique<Circle>();
    if (name == "rectangle")
        return make_unique<Rectangle>();
    if (name == "triangle")
        return make_unique<Triangle>();
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string name;

    cout << "Enter shape names (circle, rectangle, triangle; done to finish):"
         << endl;
    while (cin >> name && name != "done") {
        unique_ptr<Shape> shape = createShape(name);
        if (!shape) {
            cerr << "Unknown shape: " << name << endl;
            return 1;
        }
        shapes.push_back(move(shape));
    }

    if (!cin && !cin.eof()) {
        cerr << "Error reading shape names" << endl;
        return 1;
    }

    for (const unique_ptr<Shape> &shape : shapes)
        shape->draw();

    return 0;
}