#include <iostream>
#include "bigReal.h"

int main() {
    bigReal n1 ("11.9000000000000000000000000000000001");
    bigReal n2 ("2333333333339.1134322222222292");
    bigReal n3 = n1 + n2;
    cout << n3;
    n3 = n3 + bigReal (0.9);

}
