#include "BigDecimalIntClass.h"

// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}

// constructor that takes a string as an input.
void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }
}

// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{
    if (sign == anotherDec.sign && number == anotherDec.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}
// operator = overloading function.
BigDecimalInt& BigDecimalInt :: operator = (const BigDecimalInt &anotherDec)
{
    sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

// // operator + overloading function.
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = sign, signNumber2 = number2.sign;

    string num1 = number, num2 = number2.number;
    while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2){
        result.sign = signNumber1;

        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;

        while (it1 != num1.rend()){
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if(twoDigitsSum >= 10){
                carry = 1;
            }
            result.number = char((twoDigitsSum % 10) + '0') + result.number;
            *(it1 + 1) = char (((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }

        if(carry){
            result.number = char ((carry) + '0') + result.number;
        }

    }else{
        deque<long long> d;
        string res = "";

        if (num1 < num2)
        {
            swap(num1, num2);
            swap(signNumber1,signNumber2);
        }

        for (long long i = num1.length() - 1; i >= 0; i--)
        {
            if (num1[i] < num2[i])
            {
                num1[i] = char (((num1[i] - '0') + 10) + '0');
                num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
            else
            {
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
        }

        bool right = false;
        for (auto i : d)
        {
            res += to_string(i);
        }

        for (long long i = 0; i < res.length(); i++)
        {
            if (res[i] != '0')
            {
                right = true;
            }
            if (!right && res[i] == '0')
            {
                res.erase(i, 1);
                i--;
            }
        }
        if(res.empty())res="0";
        result.sign = signNumber1;
        result.number = res;
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    string strmin = "", res = "";
    deque<long long> d;


    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        anotherDec.number = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        number = strmin;
    }
    bool ok = false;
    if (number < anotherDec.number)
    {
        swap(number, anotherDec.number);
        ok = true;
    }
    bool nv = true;
    if (sign == '-' && anotherDec.sign == '-')
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        ok = !ok;
    }
    else if ((sign == '-' || anotherDec.sign == '-'))
    {
        string num1 = number, num2 = anotherDec.number;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;

        while (it1 != num1.rend())
        {
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if (twoDigitsSum >= 10)
            {
                carry = 1;
            }
            res = char((twoDigitsSum % 10) + '0') + res;
            *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }

        if (carry)
        {
            res = char((carry) + '0') + res;
        }
        if (sign == '-')
        {
            nv = false;
        }
    }
    else
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        nv = true;
    }
    if (!nv || ok) {
        obj.sign = '-';
    }else{
        obj.sign = '+';
    }
    bool right = false;
    for (auto i : d)
    {
        res += to_string(i);
    }
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }
    if(res.empty())res="0";
    obj.number = res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();
}

int BigDecimalInt :: Sign()
{
    if (sign == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// operator << overloading function.
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.sign == '+')
    {
        out << num.number << endl;
    }
    else
    {
        out << num.sign << num.number << endl;
    }
    return out;
}

string BigDecimalInt::getNumber() {
    return number;
}