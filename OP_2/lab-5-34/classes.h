#pragma once
using namespace std;

class TIntNumber;
class TIntNumber2;
class TIntNumber8;

//functions not full

class TIntNumber {
protected:
    int base; // the base of the number system
    vector<int> digits; // the digits of the number in the given base

public:
    TIntNumber(int _base) : base(_base) {}

    virtual void increment() = 0;
    virtual void decrement() = 0;
    virtual int toDecimal() = 0;

    void print();
};


/// //////////////////////////////////////////////////////////////////////////////////


class TIntNumber2 : public TIntNumber {
public:
    TIntNumber2(string binaryString) : TIntNumber(2) {
        for (int i = binaryString.size() - 1; i >= 0; i--) {
            digits.push_back(binaryString[i] - '0');
        }
    }

    void increment() override {
        int carry = 1;
        int i = 0;
        while (carry && i < digits.size()) {
            digits[i] += carry;
            if (digits[i] == base) {
                digits[i] = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }
            i++;
        }
        if (carry) {
            digits.push_back(1);
        }
    }

    void decrement() override {
        // not implemented for binary numbers
    }

    int toDecimal() override {
        int decimalValue = 0;
        for (int i = 0; i < digits.size(); i++) {
            decimalValue += digits[i] * pow(base, i);
        }
        return decimalValue;
    }
};

/// //////////////////////////////////////////////////////////////////////

class TIntNumber8 : public TIntNumber {
public:
    TIntNumber8(string octalString) : TIntNumber(8) {
        for (int i = octalString.size() - 1; i >= 0; i--) {
            digits.push_back(octalString[i] - '0');
        }
    }

    void increment() override {
        // not implemented for octal numbers
    }

    void decrement() override {
        int borrow = 1;
        int i = 0;
        while (borrow && i < digits.size()) {
            digits[i] -= borrow;
            if (digits[i] == -1) {
                digits[i] = base - 1;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            i++;
        }
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

    int toDecimal() override {
        int decimalValue = 0;
        for (int i = 0; i < digits.size(); i++) {
            decimalValue += digits[i] * pow(base, i);
        }
        return decimalValue;
    }
};

/// //////////////////////////////////////////////////////////////////////