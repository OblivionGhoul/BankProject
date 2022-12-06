#ifndef BANKPROJECT_BANK_H
#define BANKPROJECT_BANK_H
#include "iostream"
#include <string>
#include "BankAccount.h"
#include <vector>
#include "Alg.h"
using namespace std;

int num = 0;

class Bank {
    private:
        string name;
        string address;
        string workingHours;
        vector<BankAccount> bankAccounts;
        int numBankAcc;

    public:
        Bank(string name, string address, string workingHours) {
            this->name = name;
            this->address = address;
            this->workingHours = workingHours;
            numBankAcc = 0;
        }

        int getNumBankAcc() const {
            return numBankAcc;
        }

        int getNumSavingAcc() const {
            int numSavingAcc = 0;
            for (const auto & bankAccount : bankAccounts) {
                numSavingAcc += bankAccount.getNumSavingAcc();
            }
            return numSavingAcc;
        }

        int getNumCheckingAcc() const {
            int numCheckingAcc = 0;
            for (const auto & bankAccount : bankAccounts) {
                numCheckingAcc += bankAccount.getNumCheckingAcc();
            }
            return numCheckingAcc;
        }

        string getName() const {
            return name;
        }

        void openBankAccount() {
            string firstName, lastName, ssn;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your last name: ";
            cin >> lastName;
            cout << "Enter your ssn: ";
            cin >> ssn;

            string bankAccNum = "BNK" + to_string(num + 10000);
            BankAccount bankAccount(firstName, lastName, ssn, bankAccNum);
            bankAccounts.push_back(bankAccount);
            numBankAcc++;
            num++;

            cout << "Bank account opened successfully!" << endl;
            cout << endl;
        }

        void closeBankAccount() {
            string bankAccNum;
            cout << "Enter the bank account number: ";
            cin >> bankAccNum;

            int index = Alg::binarySearch(bankAccounts, bankAccNum);
            if (index != -1) {
                bankAccounts.erase(bankAccounts.begin() + index);
                numBankAcc--;
                cout << "Bank account closed successfully!" << endl;
                cout << endl;
            } else {
                cout << "Bank account not found!" << endl;
                cout << endl;
                closeBankAccount();
            }
            cout << endl;
        }

        void modifyAccount() {
            string bankAccNum;
            cout << "Enter the bank account number: ";
            cin >> bankAccNum;

            int index = Alg::binarySearch(bankAccounts, bankAccNum);
            if (index != -1) {
                bankAccounts[index].accountMenu();
            } else {
                cout << "Bank account not found!" << endl;
                cout << endl;
                modifyAccount();
            }
        }

        void displayAllAccountsInfo() {
            Alg::sortByBalance(bankAccounts);
            for (auto bankAccount : bankAccounts) {
                cout << "Account Number: " << bankAccount.getAccountNumber() << endl;
                cout << "First Name: " << bankAccount.getFirstName() << endl;
                cout << "Last Name: " << bankAccount.getLastName() << endl;
                cout << "Total Balance: " << bankAccount.calculateTotalBalance() << endl;
                cout << endl;
            }
        }

        void displayBriefAllAccountsInfo() {
            Alg::sortByBalance(bankAccounts);
            for (auto bankAccount : bankAccounts) {
                cout << "Account Number: " << bankAccount.getAccountNumber() << endl;
                cout << "Total Balance: " << bankAccount.calculateTotalBalance() << endl;
                cout << endl;
            }
        }

        static void displayBankMenu() {
            cout << "1. See Number Of Bank Accounts" << endl;
            cout << "2. See Number Of Saving Accounts" << endl;
            cout << "3. See Number Of Checking Accounts" << endl;
            cout << "4. Open Bank Account" << endl;
            cout << "5. Close Bank Account" << endl;
            cout << "6. Account Info and Modify" << endl;
            cout << "7. Detailed Info of All Accounts" << endl;
            cout << "8. Brief Info of All Accounts" << endl;
            cout << "9. Exit" << endl;
        }

        void runBankMenu() {
            int choice;
            do {
                cout << "Eligible Services for " << getName() << endl;
                displayBankMenu();
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Number of bank accounts: " << getNumBankAcc() << endl;
                        cout << endl;
                        break;
                    case 2:
                        cout << "Number of saving accounts: " << getNumSavingAcc() << endl;
                        cout << endl;
                        break;
                    case 3:
                        cout << "Number of checking accounts: " << getNumCheckingAcc() << endl;
                        cout << endl;
                        break;
                    case 4:
                        openBankAccount();
                        break;
                    case 5:
                        closeBankAccount();
                        break;
                    case 6:
                        modifyAccount();
                        break;
                    case 7:
                        displayAllAccountsInfo();
                        break;
                    case 8:
                        displayBriefAllAccountsInfo();
                        break;
                    case 9:
                        cout << "Have a good day!" << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                }
            } while (choice != 9);
        }
};

#endif