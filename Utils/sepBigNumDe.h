//
// Created by seulAuguestine on 2022/5/21.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMDE_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMDE_H

char  *sepBigNumDe (char *x) {//输入带符号的实数 输出小数部分
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
    for (int i = j + 1, k = 0; i < len, k < len - j; ++i, ++k) {
        FBN.decimal[k] = x[i];
        //printf("%c",FBN.decimal[k]);
    }
    return FBN.decimal;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_SEPBIGNUMDE_H
