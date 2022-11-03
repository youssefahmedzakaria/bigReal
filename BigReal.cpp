#include "BigReal.h"


BigReal::BigReal(double realNumber) {
    if (realNumber == 0.0) {
        BigDecimalInt number1(0);
        bigDecimalNum = number1;
        decimalPoint = 0;
    } else {
        string s = to_string(realNumber);
        int decimalPlace = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '.') {
                if (realNumber < 0) {
                    decimalPlace = i - 1;
                } else
                    decimalPlace = i;
                break;
            }
        }
        s.erase(remove(s.begin(), s.end(), '.'), s.end());
        BigDecimalInt number2(s);
        bigDecimalNum = number2;
        decimalPoint = decimalPlace;
    }
}

BigReal::BigReal(string RealNumber) {
    regex validInput("[+-]?([0-9]*[.])?[0-9]+");
    if (regex_match(RealNumber, validInput)) {
        int decimalPlace = 0;
        for (int i = 0; i < RealNumber.length(); ++i) {
            if (RealNumber[i] == '.') {
                if (RealNumber[0] == '-') {
                    decimalPlace = i - 1;
                } else
                    decimalPlace = i;
                break;
            }
        }
        RealNumber.erase(remove(RealNumber.begin(), RealNumber.end(), '.'), RealNumber.end());
        BigDecimalInt number2(RealNumber);
        bigDecimalNum = number2;
        decimalPoint = decimalPlace;
    } else
        return;
}

BigReal::BigReal(BigDecimalInt& bigInteger){
    bigDecimalNum = bigInteger;
}

BigDecimalInt BigReal::get_integer() {
    return bigDecimalNum;
}
// Copy constructor
BigReal::BigReal(const BigReal& other) {
    realNum = other.realNum;
    bigDecimalNum = other.bigDecimalNum;
    decimalPoint = other.decimalPoint;
    cout<<"Copied"<<endl;
}
//move constructor
BigReal::BigReal(BigReal &&other) {
    realNum =std::move(other.realNum);
    bigDecimalNum = std::move(other.bigDecimalNum);
    decimalPoint = std::move(other.decimalPoint);
    cout<<"moved"<<endl;
}
//assignment operator
BigReal &BigReal::operator=(const BigReal &other) {
    realNum = other.realNum;
    bigDecimalNum = other.bigDecimalNum;
    decimalPoint = other.decimalPoint;
    cout<<"Copied from = operator"<<endl;
    return *this;
}
//Move assignment
BigReal &BigReal::operator=(BigReal &&other) {
    realNum = std::move(other.realNum);
    bigDecimalNum = std::move(other.bigDecimalNum);
    decimalPoint = std::move(other.decimalPoint);
    cout<<"Moved from = operator"<<endl;
    return *this;
}
