//
// Created by youssef zakaria on 11/2/2022.
//
#include "BigDecimalIntClass.h"

#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H


class bigReal {

private:


public:
    bigReal (double realNumber = 0.0); // Default constructor

    bigReal (string realNumber);

    bigReal (BigDecimalInt bigInteger);

    bigReal (const bigReal& other); // Copy constructor

    bigReal (bigReal&& other); // Move constructor

    bigReal& operator= (bigReal& other); // Assignment operator

    bigReal& operator= (bigReal&& other); // Move assignment

    bigReal operator+ (bigReal& other); // Addition operator

    bigReal operator- (bigReal& other); // subtraction operator

    bool operator< (bigReal anotherReal); // Overloading the < operator

    bool operator> (bigReal anotherReal); // Overloading the > operator

    bool operator== (bigReal anotherReal); // Overloading the == operator

    int size(); // return the size of the number

    int sign(); // 1 for positive, -1 for negative

    friend ostream& operator << (ostream& out, bigReal num);
    friend istream& operator >> (istream& out, bigReal num);
};



#endif //BIGREAL_BIGREAL_H
