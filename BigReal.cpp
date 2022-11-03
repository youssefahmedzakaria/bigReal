#include "BigReal.h"




BigReal::BigReal(double realNumber) {
    if (realNumber == 0.0) {
        BigDecimalInt number1(0);
        integer = number1;
        decimalPoint = 0;
    } else {
        string s = to_string(realNumber);
        int decimalPlace;
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
        integer = number2;
        decimalPoint = decimalPlace;
    }
}

BigReal::BigReal(string RealNumber) {
    regex validInput("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+");
    if (regex_match(RealNumber, validInput)) {
        int decimalPlace;
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
        integer = number2;
        decimalPoint = decimalPlace;
    } else
        return;
}

BigReal::BigReal(BigDecimalInt bigInteger){
    integer = bigInteger;
}


