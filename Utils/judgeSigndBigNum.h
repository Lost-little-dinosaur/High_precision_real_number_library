//
// Created by seulAuguestine on 2022/5/19.
//

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
#define MAXSIZE 500
struct SigndBigNum {//有符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

int judgeSigndBigNum (char x[]) {//判断有符号整数是正数负数还是0
    struct SigndBigNum SBN;
    char c = x[0];
    if (c == '+') {
        SBN.flag = 1;
    } else if (c == '-') {
        SBN.flag = -1;
    } else {
        SBN.flag = 0;
    }
    return SBN.flag;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_JUDGESIGNDBIGNUM_H
