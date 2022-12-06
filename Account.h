#ifndef BANKPROJECT_ACCOUNT_H
#define BANKPROJECT_ACCOUNT_H
#include <string>
using namespace std;

class Account {
protected:
    double balance = 0;
    string accountNumber;

public:
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " successfully for " << accountNumber << endl;
        cout << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            cout << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn " << amount << " successfully for " << accountNumber << endl;
            cout << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    virtual void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

#endif