#include <iostream>
using namespace std;
#include "Bank.h"

int main() {
    cout << "Enter the name of the bank: " << endl;
    string name;
    getline(cin, name);
    cout << "Enter the address of the bank: " << endl;
    string address;
    getline(cin, address);
    cout << "Enter the working hours of the bank: " << endl;
    string workingHours;
    getline(cin, workingHours);

    Bank bank(name, address, workingHours);
    bank.runBankMenu();
}