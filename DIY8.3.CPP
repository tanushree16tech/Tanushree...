#include <iostream>
#include <string>

using namespace std;

class BuggyBase {
public:
    ~BuggyBase() {
        cout << "BuggyBase destructor" << endl;
    }
};

class BuggyDerived : public BuggyBase {
    int *data;

public:
    BuggyDerived() : data(new int[100]) {
        cout << "BuggyDerived allocated memory" << endl;
    }

    ~BuggyDerived() {
        delete[] data;
        cout << "BuggyDerived released memory" << endl;
    }
};

class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    int *data;

public:
    Derived() : data(new int[100]) {
        cout << "Derived allocated memory" << endl;
    }

    ~Derived() override {
        delete[] data;
        cout << "Derived released memory" << endl;
    }
};

int main(int argc, char *argv[]) {
    const string mode = argc > 1 ? argv[1] : "fixed";

    if (mode == "bug") {
        cout << "Reproducing the bug: deleting through a base pointer "
                "without a virtual destructor." << endl;
        BuggyBase *object = new BuggyDerived;
        delete object;
    } else if (mode == "fixed") {
        cout << "Fixed version: deleting through a base pointer with a "
                "virtual destructor." << endl;
        Base *object = new Derived;
        delete object;
    } else {
        cerr << "Usage: DIY83.EXE [fixed|bug]" << endl;
        return 1;
    }

    return 0;
}