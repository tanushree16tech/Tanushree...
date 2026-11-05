#include <iostream>
#include <memory>

using namespace std;

class Tracer {
public:
    Tracer() {
        cout << "Object created" << endl;
    }

    ~Tracer() {
        cout << "Object released" << endl;
    }
};

int main() {
    for (int i = 0; i < 3; ++i) {
        unique_ptr<Tracer> object = make_unique<Tracer>();
    }

    return 0;
}