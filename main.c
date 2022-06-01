#include <stdio.h>
#include "newCompute/multiplication.h"
#include "string.h"
#include "Model/struct.h"

int main() {
    struct SignedBigNum a;
    struct SignedBigNum b;

    a.flag = 1;
    b.flag = 1;
    char *s1 = "123";

    char *s2 = "0123";

    strcpy(a.numBody, s1);
    strcpy(b.numBody, s2);
    a.length = strlen(s1);
    b.length =  strlen(s2);
    printf("%s", multiplySignedBigNum(a, b).numBody);
    return 0;
}
