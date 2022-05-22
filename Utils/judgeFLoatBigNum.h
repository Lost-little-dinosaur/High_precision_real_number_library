//
// Created by seulAuguestine on 2022/5/19.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGEFLOATBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGEFLOATBIGNUM_H

int judgeFloatBigNum (char x[]) {//判断高精度实数是正数负数还是0
    FloatBigNum FBN;
    char c = x[0];
    if (c == '+') {
        FBN.flag = 1;
    } else if (c == '-') {
        FBN.flag = -1;
    } else {
        FBN.flag = 0;
    }
    return FBN.flag;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGEFLOATBIGNUM_H
