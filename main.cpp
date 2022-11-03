#include <iostream>
#include "BigReal.h"

int main() {
    BigDecimalInt n0 ("123456789012345678901234567890");
    BigReal n1 (22.56);
    BigReal n2 ("11.9000000000000000000000000000000001");
    BigReal n3 ("123456789123456789");
    cout<<n1.get_integer();
    cout<<n2.get_integer();
    cout<<n3.get_integer();
    BigReal n4 = n3;
    cout<<n4.get_integer();
    BigReal n5= (BigReal&&)n2;
    cout<<n5.get_integer();
    BigReal n6(n0);
    cout<<n6.get_integer();
    n2 = (BigReal&&) n3;
    cout<<n2.get_integer();
}