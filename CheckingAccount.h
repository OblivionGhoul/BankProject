#ifndef BANKPROJECT_CHECKINGACCOUNT_H
#define BANKPROJECT_CHECKINGACCOUNT_H
#include "Account.h"

class CheckingAccount : public Account {
    private:
        double maxCapacity;
        bool isLocked;

    public:
        CheckingAccount(string accNum) {
            accountNumber = accNum;
            maxCapacity = 1000;
            isLocked = false;
        }

        void modifyAccount() {
            int choice;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Max Capacity" << endl;
            cout << "4. Lock Sub-Account" << endl;
            cout << "5. Unlock Sub-Account" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            while (!(choice >= 1 && choice <= 6)) {
                cout << "Invalid choice. Please enter again: ";
                cin >> choice;
            }

            switch (choice) {
                case 1: {
                    double amount;
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;
                    deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;
                    withdraw(amount);
                    break;
                }
                case 3: {
                    double amount;
                    cout << "Enter the max capacity: ";
                    cin >> amount;
                    setMaxCapacity(amount);
                    break;
                }
                case 4: {
                    lockSubAccount();
                    break;
                }
                case 5: {
                    unlockSubAccount();
                    break;
                }
                case 6: {
                    cout << "Exiting..." << endl;
                    cout << endl;
                    break;
                }
                default: {
                    cout << "Invalid choice!" << endl;
                    break;
                }
            }
        }

        void deposit(double amount) override {
            if (isLocked) {
                cout << "Sub-Account is locked. Cannot deposit!" << endl;
                return;
            }
            if (balance + amount > maxCapacity) {
                cout << "Cannot deposit. Exceeds max capacity!" << endl;
                return;
            }
            Account::deposit(amount);
        }

        void withdraw(double amount) override {
            if (isLocked) {
                cout << "Sub-Account is locked. Cannot withdraw!" << endl;
                return;
            }
            if (amount > balance) {
                cout << "Insufficient balance!" << endl;
                cout << endl;
            } else {
                balance -= amount;
                cout << "Withdrawn " << amount << " successfully for " << accountNumber << endl;
                cout << endl;
            }
        }

        void setMaxCapacity(double amount) {
            maxCapacity = amount;
        }

        void lockSubAccount() {
            isLocked = true;
            cout << "Sub-account locked!" << endl;
            cout << endl;
        }

        void unlockSubAccount() {
            isLocked = false;
            cout << "Sub-account unlocked!" << endl;
            cout << endl;
        }

        void displayAccountInfo() override {
            Account::displayAccountInfo();
            cout << "Max Capacity: " << maxCapacity << endl;

            if (isLocked) {
                cout << "Is Locked: True" << endl;
            } else {
                cout << "Is Locked: False" << endl;
            }

            cout << endl;
        }
};

#endif