#include <iomanip>
#include <iostream>

using namespace std;

class Money {
    long long totalPaise;

public:
    Money(long long rupees, long long paise)
        : totalPaise(rupees * 100 + paise) {}

    Money operator+(const Money &other) const {
        return Money(0, totalPaise + other.totalPaise);
    }

    Money operator-(const Money &other) const {
        return Money(0, totalPaise - other.totalPaise);
    }

    void display() const {
        const bool negative = totalPaise < 0;
        const unsigned long long amount =
            negative ? 0ULL - static_cast<unsigned long long>(totalPaise)
                     : static_cast<unsigned long long>(totalPaise);

        if (negative)
            cout << "-";
        cout << amount / 100 << "." << setfill('0') << setw(2) << amount % 100
             << setfill(' ');
    }
};

int main() {
    Money first(12, 75);
    Money second(8, 90);

    cout << "Sum: ";
    (first + second).display();
    cout << " rupees" << endl;

    cout << "Difference: ";
    (first - second).display();
    cout << " rupees" << endl;

    return 0;
}