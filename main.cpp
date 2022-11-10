#include <iostream>
#include "BigReal.h"

int main() {
    BigDecimalInt n0 ("123456789012345678901234567890");
    BigReal n1 ("200.65789888888");
    BigReal n2 ("-11.9000000000000000000000000000000001");
    BigReal n6 = n1+n2;
    cout << n6.get_integer() << endl;
    BigReal n7 = n1-n2;
    cout << n7.get_integer() << endl;
    BigReal n3 ("-2333333333339.1134322222222292");
    BigReal n4 ("2000011.900000000001");
    BigReal n5 (n3);

    int x= n2>n3;
    int y= n2<n3;
    int z= n5==n3;


    cout << "num1 = " << n1 << endl;
    cout << "num2 = " << n2 << endl;
    cout << "num1 + num2 = " << n6.get_integer() << endl;
    cout << "num2 - num1 = " << n7.get_integer() << endl;
    cout << "num5 = " << n3 << endl;
    cout << "num2 > num3 = " << x << endl;
    cout << "num2 < num3 = " << y << endl;
    cout << "num5 == num3 = " << z << endl;

//    cout<<n1.get_integer()<<endl;
//    cout<<n2.get_integer()<<endl;
//    cout<<n3.get_integer()<<endl;
//    BigReal n4 = n3;
//    cout<<n4.get_integer()<<endl;
//    BigReal n5= (BigReal&&)n2;
//    cout<<n5.get_integer()<<endl;
//    BigReal n6(n0);
//    cout<<n6.get_integer()<<endl;
//    n1 = (BigReal&&) n3;
//    cout<<n1.get_integer()<<endl;


//    BigReal n15 = n3 + n2;
//    cout<<n15.get_integer()<<endl;
//    BigReal n16 = n3 - n2;
//    cout<<n16.get_integer()<<endl;
}