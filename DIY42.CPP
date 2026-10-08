#include <iostream>
using namespace std;

class Stack {
    int *a, top, size;

public:
    Stack(int s) {
        size = s;
        top = -1;
        a = new int[size];
    }

    void push(int x) {
        if(top < size-1)
            a[++top] = x;
    }

    void pop() {
        if(top >= 0)
            cout << "Popped: " << a[top--] << endl;
    }

    ~Stack() {
        delete[] a;
        cout << "Stack memory released";
    }
};

int main() {
    Stack s(3);

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();
}