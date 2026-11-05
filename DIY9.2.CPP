#include <iostream>
#include <stdexcept>

using namespace std;

class Overflow : public runtime_error {
public:
    Overflow() : runtime_error("Stack overflow") {}
};

class Underflow : public runtime_error {
public:
    Underflow() : runtime_error("Stack underflow") {}
};

class Stack {
    static const int capacity = 3;
    int values[capacity];
    int top;

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top + 1 == capacity)
            throw Overflow();
        values[++top] = value;
    }

    int pop() {
        if (top < 0)
            throw Underflow();
        return values[top--];
    }
};

int main() {
    Stack stack;

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
    } catch (const Overflow &error) {
        cout << "Push failed: " << error.what() << endl;
    }

    try {
        for (int i = 0; i < 4; ++i) {
            const int value = stack.pop();
            cout << "Popped: " << value << endl;
        }
    } catch (const Underflow &error) {
        cout << "Pop failed: " << error.what() << endl;
    }

    return 0;
}