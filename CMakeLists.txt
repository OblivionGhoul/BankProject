cmake_minimum_required(VERSION 3.23)
project(BankProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankProject
        main.cpp BankAccount.h Bank.h CheckingAccount.h SavingAccount.h Account.h Alg.h)
