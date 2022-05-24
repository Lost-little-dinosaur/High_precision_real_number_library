//
// Created by Dinosaur on 2022/5/19.
//
#define MAXSIZE 500//数字的最大长度为500

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_STRUCT_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_STRUCT_H

struct UnsigndBignNum {//无符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//0表示0，可以不做任何操作，1表示正数
};

struct SigndBigNum {//有符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

struct FloatBigNum {//超高精度实数
    int lengthIntager;//表示数据的位数
    int lengthDecimal;//表示数据的位数
    char intager[MAXSIZE];//整数部分
    char decimal[MAXSIZE];//小数部分
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_STRUCT_H
