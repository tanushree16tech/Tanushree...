#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

class Fraction {
    int numerator;
    int denominator;

    void simplify() {
        if (denominator == 0)
            throw invalid_argument("Denominator cannot be zero");

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        const int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        simplify();
    }

    friend istream &operator>>(istream &input, Fraction &fraction) {
        int n, d;
        if (input >> n >> d) {
            if (d == 0) {
                input.setstate(ios::failbit);
            } else {
                fraction = Fraction(n, d);
            }
        }
        return input;
    }

    friend ostream &operator<<(ostream &output, const Fraction &fraction) {
        return output << fraction.numerator << "/" << fraction.denominator;
    }
};

int main() {
    Fraction first, second;

    cout << "Enter two fractions (numerator denominator): ";
    if (!(cin >> first >> second)) {
        cerr << "Invalid fraction input. Denominators must not be zero." << endl;
        return 1;
    }

    cout << "Simplified fractions: " << first << " and " << second << endl;
    return 0;
}