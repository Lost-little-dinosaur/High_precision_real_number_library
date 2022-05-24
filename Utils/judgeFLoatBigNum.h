//
// Created by seulAuguestine on 2022/5/19.
//
#include ""

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGEFLOATBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGEFLOATBIGNUM_H
#define MAXSIZE 500

struct FloatBigNum {//超高精度实数
    int lengthIntager;//表示数据的位数
    int lengthDecimal;//表示数据的位数
    char intager[MAXSIZE];//整数部分
    char decimal[MAXSIZE];//小数部分
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

int judgeFloatBigNum (char x[]) {//判断高精度实数是正数负数还是0
    struct FloatBigNum FBN;
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
