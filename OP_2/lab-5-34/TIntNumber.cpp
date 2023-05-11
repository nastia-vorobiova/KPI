#include "header.h"

//class functions full

void TIntNumber::print() {
    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i];
    }
    cout << endl;
}