#ifndef BANKPROJECT_SAVINGACCOUNT_H
#define BANKPROJECT_SAVINGACCOUNT_H
#include "Account.h"

class SavingAccount : public Account {
    public:
        SavingAccount(string accNum) {
            accountNumber = accNum;
        }

        void modifyAccount() {
            int choice;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            while (!(choice >= 1 && choice <= 3)) {
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

        void displayAccountInfo() override {
            Account::displayAccountInfo();
            cout << endl;
        }
};

#endif