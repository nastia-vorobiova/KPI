#include "header.h"

int main() {
    int m, n;
    cout << "How many binary numbers do you want to create? ";
    cin >> m;

    cout << "Enter binary numbers:" << endl;
    vector<TIntNumber*> binaryNumbers;
    for (int i = 0; i < m; i++) {
        binaryNumbers = AddNewBinaryNumber(binaryNumbers);
    }

    cout << "How many octal numbers do you want to create? ";
    cin >> n;

    cout << "Enter octal numbers:" << endl;
    vector<TIntNumber*> octalNumbers;
    for (int i = 0; i < n; i++) {
        octalNumbers = AddNewOctalNumber(octalNumbers);
    }

    cout << "\nBefore incrementing and decrementing:" << endl;
    cout << "Binary numbers:" << endl;
    for (int i = 0; i < m; i++) {
        binaryNumbers[i]->print();
    }

    cout << "Octal numbers:" << endl;
    for (int i = 0; i < n; i++) {
        octalNumbers[i]->print();
    }

    cout << "\nAfter incrementing and decrementing:" << endl;
    for (int i = 0; i < m; i++) {
        binaryNumbers[i]->increment();
    }
    for (int i = 0; i < n; i++) {
        octalNumbers[i]->decrement();
    }
    cout << "Binary numbers:" << endl;
    for (int i = 0; i < m; i++) {
        binaryNumbers[i]->print();
    }
    cout << "Octal numbers:" << endl;
    for (int i = 0; i < n; i++) {
        octalNumbers[i]->print();
    }

    cout << "\nTurn numbers to decimal:" << endl;

    vector<TIntNumber*> allNumbers;
    allNumbers.insert(allNumbers.end(), binaryNumbers.begin(), binaryNumbers.end());
    allNumbers.insert(allNumbers.end(), octalNumbers.begin(), octalNumbers.end());

    int smallestDecimal = findSmallestDecimal(allNumbers);

    cout << "\nSmallest decimal value: " << smallestDecimal << endl;
}
