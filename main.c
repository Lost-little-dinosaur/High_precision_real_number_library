#include <stdio.h>
#include "newCompute/multiplication.h"
#include "string.h"
#include "Model/struct.h"

int main() {
    struct UnsignedBigNum a;
    struct UnsignedBigNum b;

    a.flag = 1;
    b.flag = 1;
    strcpy(a.numBody, "123");
    strcpy(b.numBody, "1234");
    a.length = 3;
    b.length = 4;
    printf("%s", multiplyUnsignedBigNum(a, b).numBody);
    return 0;
}
