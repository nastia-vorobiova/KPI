#include "header.h"

vector<TIntNumber*> AddNewBinaryNumber(vector<TIntNumber*> Numbers)
{
    string String;
    cin >> String;
    TIntNumber* Number = new TIntNumber2(String);
    Numbers.push_back(Number);
    return Numbers;
}

vector<TIntNumber*> AddNewOctalNumber(vector<TIntNumber*> Numbers)
{
    string String;
    cin >> String;
    TIntNumber* Number = new TIntNumber8(String);
    Numbers.push_back(Number);
    return Numbers;
}

int findSmallestDecimal(vector<TIntNumber*> allNumbers)
{
    int smallestDecimal = INT_MAX;
    for (int i = 0; i < allNumbers.size(); i++) {
        int decimalValue = allNumbers[i]->toDecimal();
        cout << decimalValue << endl;
        if (decimalValue < smallestDecimal) {
            smallestDecimal = decimalValue;
        }
    }
    return smallestDecimal;
}