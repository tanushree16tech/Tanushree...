#include <iostream>
using namespace std;

class Order {
    static int nextID;
    int id;

public:
    Order() {
        id = nextID++;
    }

    void display() {
        cout << "Order ID: " << id << endl;
    }
};

int Order::nextID = 1001;

int main() {
    Order a, b, c;

    a.display();
    b.display();
    c.display();
}