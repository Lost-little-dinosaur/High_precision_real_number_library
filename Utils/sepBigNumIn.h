//
// Created by seulAuguestine on 2022/5/21.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H

char  *sepBigNumIn (char *x) {//输入带符号的实数 输出整数部分
    FloatBigNum FBN;
    int j, k, len;
    int i;
    len = strlen(x);
    for (i = 0; i < len; i++) {
        if (x[i] == '.') {
            break;
        }
    }
    j = i;
    for (i = 1, k = 0; i < j, k < j - 1; ++i, ++k) {
        FBN.intager[k] = x[i];
        //printf("%c", FBN.intager[k]);
    }
    return FBN.intager;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMIN_H
