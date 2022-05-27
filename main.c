#include <stdio.h>
#include "Compute/multiplyUnsigndBignNum.h"
#include "Compute/UnsignedBigNum.h"

int main() {
    struct UnsignedBigNum a;
    struct UnsignedBigNum b;

    a.flag = 1;
    b.flag = 1;
    strcpy(a.numBody, "123");
    strcpy(b.numBody, "1234");
    a.length = 3;
    b.length = 4;
//    printf("%s", multiplyUnsigndBigNum(a, b).numBody);
    test();
    return 0;
}
