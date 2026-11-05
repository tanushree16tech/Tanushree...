
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class InsufficientFunds : public runtime_error {
public:
    explicit InsufficientFunds(const string &message) : runtime_error(message) {}
};

class BankAccount {
    string owner;
    double balance;

public:
    BankAccount(const string &accountOwner, double initialBalance)
        : owner(accountOwner), balance(initialBalance) {
        if (initialBalance < 0)
            throw invalid_argument("Initial balance cannot be negative");
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Deposit must be positive");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdrawal must be positive");
        if (amount > balance)
            throw InsufficientFunds("Insufficient funds for withdrawal");
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    const string &getOwner() const {
        return owner;
    }
};

int main() {
    try {
        BankAccount account("Asha", 1000);
        account.deposit(500);
        account.withdraw(200);
        cout << account.getOwner() << " balance = " << account.getBalance()
             << endl;

        account.withdraw(2000);
    } catch (const InsufficientFunds &error) {
        cerr << "Withdrawal denied: " << error.what() << endl;
    } catch (const exception &error) {
        cerr << "Account error: " << error.what() << endl;
        return 1;
    }

    return 0;
}