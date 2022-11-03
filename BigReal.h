#include "BigDecimalIntClass.h"

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H


class BigReal {

private:
    BigDecimalInt integer;

    int decimalPoint;

public:

    BigReal (double realNumber); // Default constructor

    BigReal (string realNumber);

    BigReal (BigDecimalInt bigInteger);

    BigReal (const BigReal& other); // Copy constructor

    BigReal (BigReal&& other); // Move constructor

    BigReal& operator= (BigReal& other); // Assignment operator

    BigReal& operator= (BigReal&& other); // Move assignment

    BigReal operator+ (BigReal& other); // Addition operator

    BigReal operator- (BigReal& other); // subtraction operator

    bool operator< (BigReal anotherReal); // Overloading the < operator

    bool operator> (BigReal anotherReal); // Overloading the > operator

    bool operator== (BigReal anotherReal); // Overloading the == operator

    int size(); // return the size of the number

    int sign(); // 1 for positive, -1 for negative

    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& out, BigReal num);
};



#endif //BIGREAL_BIGREAL_H
