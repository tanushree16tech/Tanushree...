#include <iostream>

using namespace std;

class Account {
protected:
    double balance;

public:
    explicit Account(double amount) : balance(amount) {}
    virtual double calculateInterest() const = 0;
    virtual ~Account() = default;
};

class Savings : public Account {
public:
    explicit Savings(double amount) : Account(amount) {}

    double calculateInterest() const override {
        return balance * 0.04;
    }
};

class Current : public Account {
public:
    explicit Current(double amount) : Account(amount) {}

    double calculateInterest() const override {
        return balance * 0.02;
    }
};

int main() {
    Account *accounts[] = {new Savings(1000), new Current(1000)};

    for (const Account *account : accounts)
        cout << "Interest: " << account->calculateInterest() << endl;

    for (Account *account : accounts)
        delete account;

    return 0;
}