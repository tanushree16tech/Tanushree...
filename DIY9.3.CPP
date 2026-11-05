#include <iostream>
#include <stdexcept>

using namespace std;

class MathError : public runtime_error {
public:
    explicit MathError(const string &message) : runtime_error(message) {}
};

class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("Division by zero") {}
};

void divide(int numerator, int denominator) {
    if (denominator == 0)
        throw DivideByZero();
    cout << numerator << " / " << denominator << " = "
         << static_cast<double>(numerator) / denominator << endl;
}

int main() {
    cout << "Base catch first: the derived DivideByZero is caught as MathError."
         << endl;
    try {
        divide(10, 0);
    } catch (const MathError &error) {
        cout << "Caught MathError: " << error.what() << endl;
    }

    cout << "Derived catch first: DivideByZero is handled specifically." << endl;
    try {
        divide(10, 0);
    } catch (const DivideByZero &error) {
        cout << "Caught DivideByZero: " << error.what() << endl;
    } catch (const MathError &error) {
        cout << "Caught other MathError: " << error.what() << endl;
    }

    return 0;
}