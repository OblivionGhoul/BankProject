#ifndef BANKPROJECT_BANKACCOUNT_H
#define BANKPROJECT_BANKACCOUNT_H
#include "iostream"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "Account.h"
#include <string>
#include <vector>
#include "Alg.h"
using namespace std;

class BankAccount : public Account {
    private:
        string firstName;
        string lastName;
        string ssn;
        int numSavingAcc;
        int numCheckingAcc;
        vector<SavingAccount> savingAccounts;
        vector<CheckingAccount> checkingAccounts;

    public:
        BankAccount(string firstName, string lastName, string ssn, string accountNumber) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->ssn = ssn;
            this->accountNumber = accountNumber;
            numSavingAcc = 0;
            numCheckingAcc = 0;
        }

        string getAccountNumber() {
            return accountNumber;
        }

        string getFirstName() const {
            return firstName;
        }

        string getLastName() const {
            return lastName;
        }

        int getNumSavingAcc() const {
            return numSavingAcc;
        }

        int getNumCheckingAcc() const {
            return numCheckingAcc;
        }

        double getBalance() {
            balance = calculateTotalBalance();
            return balance;
        }

        void accountMenu() {
            int choice;
            do {
                cout << "Eligible Services for " << accountNumber << endl;
                displayAccountMenu();
                cin >> choice;
                switch (choice) {
                    case 1:
                        openSavingAccount();
                        break;
                    case 2:
                        openCheckingAccount();
                        break;
                    case 3:
                        modifySubAccount();
                        break;
                    case 4:
                        closeSubAccount();
                        break;
                    case 5:
                        displayAllSubAccountsInfo();
                        break;
                    case 6:
                        displayBriefAllSubAccountsInfo();
                        break;
                    case 7:
                        cout << "Have a good day!" << endl;
                        cout << endl;
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                }
            } while (choice != 7);
        }

        static void displayAccountMenu() {
            cout << "1. Open saving sub-account" << endl;
            cout << "2. Open checking sub-account" << endl;
            cout << "3. Modify a Sub-account" << endl;
            cout << "4. Close a Sub-account" << endl;
            cout << "5. See detailed bank account info" << endl;
            cout << "6. See brief account info" << endl;
            cout << "7. Exit" << endl;
        }

        void openSavingAccount() {
            string accNum = "SAV" + to_string(numSavingAcc + 1000);
            SavingAccount savingAccount(accNum);
            if (numSavingAcc == 0) {
                savingAccount.deposit(100);
            }
            savingAccounts.push_back(savingAccount);
            Alg::sortByBalance(savingAccounts);
            numSavingAcc++;

            cout << "Saving account opened successfully!" << endl;
            cout << endl;
        }

        void openCheckingAccount() {
            string accNum = "CHK" + to_string(numCheckingAcc + 6000);
            CheckingAccount checkingAccount(accNum);
            checkingAccounts.push_back(checkingAccount);
            Alg::sortByBalance(checkingAccounts);
            numCheckingAcc++;

            cout << "Checking account opened successfully!" << endl;
            cout << endl;
        }

        void modifySubAccount() {
            cout << "Enter the account number of the sub-account you want to modify: ";
            string accNum;
            cin >> accNum;

            int subAccIndex;

            if (accNum.substr(0, 3) == "SAV") {
                subAccIndex = Alg::binarySearch(savingAccounts, accNum);
                if (subAccIndex == -1) {
                    cout << "Invalid account number!" << endl;
                    cout << endl;
                    modifySubAccount();
                }
                savingAccounts[subAccIndex].modifyAccount();
            } else if (accNum.substr(0, 3) == "CHK") {
                subAccIndex = Alg::binarySearch(checkingAccounts, accNum);
                if (subAccIndex == -1) {
                    cout << "Invalid account number!" << endl;
                    cout << endl;
                    modifySubAccount();
                }
                checkingAccounts[subAccIndex].modifyAccount();
            } else {
                cout << "Invalid account number!" << endl;
                cout << endl;
                modifySubAccount();
            }
        }

    void closeSubAccount() {
        cout << "Enter the account number of the sub-account you want to close: ";
        string accNum;
        cin >> accNum;

        int subAccIndex;

        if (accNum.substr(0, 3) == "SAV") {
            subAccIndex = Alg::binarySearch(savingAccounts, accNum);
            if (subAccIndex == -1) {
                cout << "Invalid account number!" << endl;
                cout << endl;
                closeSubAccount();
            }
            savingAccounts.erase(savingAccounts.begin() + subAccIndex);
            numSavingAcc--;
            cout << "Sub-account closed successfully!" << endl;
            cout << endl;
        } else if (accNum.substr(0, 3) == "CHK") {
            subAccIndex = Alg::binarySearch(checkingAccounts, accNum);
            if (subAccIndex == -1) {
                cout << "Invalid account number!" << endl;
                cout << endl;
                closeSubAccount();
            }
            checkingAccounts.erase(checkingAccounts.begin() + subAccIndex);
            numCheckingAcc--;
            cout << "Sub-account closed successfully!" << endl;
            cout << endl;
        } else {
            cout << "Invalid account number!" << endl;
            cout << endl;
            closeSubAccount();
        }
    }

    void displayAllSubAccountsInfo() {
        Alg::sortByBalance(savingAccounts);
        Alg::sortByBalance(checkingAccounts);
        cout << "Saving Accounts: " << endl;
        for (auto & savingAccount : savingAccounts) {
            savingAccount.displayAccountInfo();
        }
        cout << endl;
        cout << "Checking Accounts: " << endl;
        for (auto & checkingAccount : checkingAccounts) {
            checkingAccount.displayAccountInfo();
        }
        cout << endl;
    }

    double calculateTotalBalance() {
        double totalBalance = 0;
        for (auto & savingAccount : savingAccounts) {
            totalBalance += savingAccount.getBalance();
        }
        for (auto & checkingAccount : checkingAccounts) {
            totalBalance += checkingAccount.getBalance();
        }
        return totalBalance;
    }

    void displayBriefAllSubAccountsInfo() {
        int numSubAcc = numSavingAcc + numCheckingAcc;
        cout << "Aggregated Balance of " << accountNumber << " with " << numSubAcc << " sub-accounts is "<< getBalance() << endl;
        cout << endl;
    }
};

#endif