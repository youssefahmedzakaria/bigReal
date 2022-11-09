#include <iostream>
#include "BigReal.h"

int main() {
    BigDecimalInt n0 ("123456789012345678901234567890");
    BigReal n1 (22.56);
    BigReal n2 ("-11.9000000000000000000000000000000001");
    BigReal n3 ("-2333333333339.1134322222222292");
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
    BigReal n15 = n3 + n2;
    cout<<n15.get_integer()<<endl;
    BigReal n16 = n3 - n2;
    cout<<n16.get_integer()<<endl;
}