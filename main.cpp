#include <iostream>
#include "BigReal.h"


int main() {
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3;
    n3 = n3 + BigReal (0.9);
}
