#ifndef BANKPROJECT_ALG_H
#define BANKPROJECT_ALG_H
#include <vector>
#include <string>
using namespace std;

class Alg {
    public:
        template<typename T>
        static int binarySearch(vector<T> &inVec, string accNum) {
            int first = 0;
            int last = inVec.size() - 1;
            int middle;
            int position = -1;
            bool found = false;

            while (!found && first <= last) {
                middle = (first + last) / 2;
                if (inVec[middle].getAccountNumber() == accNum) {
                    found = true;
                    position = middle;
                } else if (inVec[middle].getAccountNumber() > accNum) {
                    last = middle - 1;
                } else {
                    first = middle + 1;
                }
            }
            if (found) {
                return position;
            } else {
                return -1;
            }
        }

        template <typename T>
        static void sortByBalance(vector<T> &inVec) {
            for (int i = 0; i < inVec.size(); i++) {
                for (int j = 0; j < inVec.size() - 1; j++) {
                    if (inVec[j].getBalance() > inVec[j + 1].getBalance()) {
                        T temp = inVec[j];
                        inVec[j] = inVec[j + 1];
                        inVec[j + 1] = temp;
                    }
                }
            }
        }
};

#endif