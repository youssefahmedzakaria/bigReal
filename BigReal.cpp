#include "BigReal.h"


BigReal::BigReal(double realNumber) {
    if (realNumber == 0.0) {
        BigDecimalInt number1(0);
        rNum = number1.getNumber();
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
        rNum = realNumber;
        decimalPoint = decimalPlace;
    }
}

//constructor edited
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
        rNum = RealNumber;
        decimalPoint = decimalPlace;
    }
}

int sign(string s) {
    if (s[0] == '-') {
        return -1;
    } else
        return 1;
}

BigReal::BigReal(BigDecimalInt& bigInteger){
    rNum = bigInteger.getNumber();
}

string BigReal::get_integer() {
    return rNum;
}

// Copy constructor
BigReal::BigReal(const BigReal& other) {
    rNum = other.rNum;
    decimalPoint = other.decimalPoint;
//    cout<<"Copied"<<endl;
}

//move constructor
BigReal::BigReal(BigReal &&other) {
    rNum =std::move(other.rNum);
    decimalPoint = std::move(other.decimalPoint);
//    cout<<"moved"<<endl;
}

//assignment operator
BigReal &BigReal::operator=(const BigReal &other) {
    rNum = other.rNum;
    decimalPoint = other.decimalPoint;
//    cout<<"Copied from = operator"<<endl;
    return *this;
}

//Move assignment
BigReal &BigReal::operator=(BigReal &&other) {
    rNum = std::move(other.rNum);
    decimalPoint = std::move(other.decimalPoint);
//    cout<<"Moved from = operator"<<endl;
    return *this;
}

//plus operator
BigReal BigReal::operator+(BigReal &other) {
    string s1 = rNum;
    string s2 = other.rNum;
//    to compare the signs of the numbers while adding
    char sign1 = s1[0];
    char sign2 = s2[0];
//    to remove the decimal point from the numbers to do the addition
    s1.erase(remove(s1.begin(), s1.end(), '.'), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), '.'), s2.end());
//    to remove the sign from the numbers to do the addition
    s1.erase(remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), '-'), s2.end());

//adding zeros to the numbers to make them equal in length from both sides
    if (decimalPoint < other.decimalPoint) {
        int diff = other.decimalPoint - decimalPoint;
        s1.insert(0, diff, '0');
    } else if (decimalPoint > other.decimalPoint) {
        int diff = decimalPoint - other.decimalPoint;
        s2.insert(0, diff, '0');
    }
    long long n1 = s2.size() - s1.size();
    long long n2 = s1.size() - s2.size();
    if (s1.size() < s2.size()) {
        for (long long i = 0; i < n1; ++i) {
            s1 += "0";
        }
    }
    if (s2.size() < s1.size()) {
        for (long long i = 0; i < n2; ++i) {
            s2 += "0";
        }
    }
//here's the number after making them equal in length
    cout << "the first number = " << s1 << endl;
    cout << "the second number = " << s2 << endl<<endl;
    cout<<"result = ";
//    to do the addition
    BigDecimalInt number1(s1);
    BigDecimalInt number2(s2);
    if (sign1 == '-' && sign2 == '-') {
        BigDecimalInt number3 = number1 + number2;
        string s3 = number3.getNumber();
        s3.insert(0, 1, '-');
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos+1, 1, '.');
        BigReal result(s3);
        return result;
    } else if (sign1 == '-' && sign2 != '-') {
        BigDecimalInt number3 = number2 - number1;
        string s3 = number3.getNumber();
        s3.insert(0, 1, '-');
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos+1, 1, '.');
        BigReal result(s3);
        return result;
    } else if (sign1 != '-' && sign2 == '-') {
        BigDecimalInt number3 = number1 - number2;
        string s3 = number3.getNumber();
        s3.insert(0, 1, '-');
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos+1, 1, '.');
        BigReal result(s3);
        return result;
    } else {
        BigDecimalInt number3 = number1 + number2;
        string s3 = number3.getNumber();
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos, 1, '.');
        BigReal result(s3);
        return result;
    }
}

BigReal BigReal::operator-(BigReal &other) {
    string s1 = rNum;
    string s2 = other.rNum;

//    to compare the signs of the numbers while adding
    char sign1 = s1[0];
    char sign2 = s2[0];
//    to remove the decimal point from the numbers to do the addition
    s1.erase(remove(s1.begin(), s1.end(), '.'), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), '.'), s2.end());
//    to remove the sign from the numbers to do the addition
    s1.erase(remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), '-'), s2.end());

//adding zeros to the numbers to make them equal in length from both sides
    if (decimalPoint < other.decimalPoint) {
        int diff = other.decimalPoint - decimalPoint;
        s1.insert(0, diff, '0');
    } else if (decimalPoint > other.decimalPoint) {
        int diff = decimalPoint - other.decimalPoint;
        s2.insert(0, diff, '0');
    }
    long long n1 = s2.size() - s1.size();
    long long n2 = s1.size() - s2.size();
    if (s1.size() < s2.size()) {
        for (long long i = 0; i < n1; ++i) {
            s1 += "0";
        }
    }
    if (s2.size() < s1.size()) {
        for (long long i = 0; i < n2; ++i) {
            s2 += "0";
        }
    }
//here's the number after making them equal in length
    cout << "the first number = " << s1 << endl;
    cout << "the second number = " << s2 << endl << endl;
    cout << "result = ";
    BigDecimalInt number1(s1);
    BigDecimalInt number2(s2);
//    to do the subtraction
    if (sign1 != '-' && sign2 == '-') {
        BigDecimalInt number2(s2);
        BigDecimalInt number3 = number1 - number2;
        string s3 = number3.getNumber();
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos, 1, '.');
        BigReal res(s3);
        return res;
    } else if (sign1 == '-' && sign2 != '-') {
        BigDecimalInt number1(s1);
        BigDecimalInt number3 = number2 - number1;
        string s3 = number3.getNumber();
        s3.insert(0, 1, '-');
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos + 1, 1, '.');
        BigReal res(s3);
        return res;
    } else if (sign1 == '-' && sign2 == '-') {
        BigDecimalInt number1(s1);
        BigDecimalInt number2(s2);
        BigDecimalInt number3 = number1 - number2;
        string s3 = number3.getNumber();
        s3.insert(0, 1, '-');
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos + 1, 1, '.');
        BigReal res(s3);
        return res;
    } else {
        BigDecimalInt number3 = number1 - number2;
        string s3 = number3.getNumber();
        int pos = max(decimalPoint, other.decimalPoint);
        s3.insert(pos, 1, '.');
        BigReal res(s3);
        return res;
    }
}


