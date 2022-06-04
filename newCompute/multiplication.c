//
// Created by Dinosaur on 2022/5/27.
//

#include "multiplication.h"
#include "../Model/struct.h"
#include "plus.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char *reverseString(char *str, int len) {
    char *reternStr = (char *) malloc(len);;
    for (int i = 0; i < len; ++i) {
        reternStr[i] = str[len - i - 1];
    }
    return reternStr;
}

int judgeZero(char *numBody, int len) {//判断一个字符串是否全为0
    for (int i = 0; i < len; ++i) {
        if (numBody[i] != '0') {
            return 1;
        }
    }
    return 0;
}

struct UnsignedBigNum multiplyUnsignedBigNum(struct UnsignedBigNum a, struct UnsignedBigNum b)//无符号大数乘法
{
    //初始化变量
    //用于返回的结构体
    struct UnsignedBigNum returnTemp;
    //初始化返回结构体
    returnTemp.length = 1;
    strcpy(returnTemp.numBody, "0");
    returnTemp.flag = 0;
    if (b.flag == 0 || a.flag == 0)//如果a为0或者b为0
    {
        //结果可以直接返回
        return returnTemp;
    }
    //用于临时记录每一次单位乘法的结果

    struct UnsignedBigNum eachTemp;
    //临时变量长度初始化为0
    eachTemp.length = 0;
    //用于进位的临时变量
    int tempJinwei;
    //判断出哪个变量更长
    struct UnsignedBigNum maxNum;
    struct UnsignedBigNum minNum;
    //临时用于保存结果的变量
    struct UnsignedBigNum returnSaveTemp;


    //翻转字符串
    if (b.length > a.length)//如果b的长度大于a
    {
        //就把b的值复制给maxNum
        maxNum.length = b.length;
        maxNum.flag = b.flag;
        strcpy(maxNum.numBody, reverseString(b.numBody, b.length)); //将b的numBody翻转后给临时变量

        //把a的值复制给minNum
        minNum.length = a.length;
        minNum.flag = a.flag;
        strcpy(minNum.numBody, reverseString(a.numBody, a.length)); //将a的numBody翻转后给临时变量

    } else//否则
    {
        //就把a的值复制给maxNum
        maxNum.length = a.length;
        maxNum.flag = a.flag;
        strcpy(maxNum.numBody, reverseString(a.numBody, a.length)); //将a的numBody翻转后给临时变量

        //把b的值复制给minNum
        minNum.length = b.length;
        minNum.flag = b.flag;
        strcpy(minNum.numBody, reverseString(b.numBody, b.length)); //将a的numBody翻转后给临时变量

    }

    int ii = minNum.length - 1;
    while (minNum.numBody[ii] == '0' && ii >= 0)//翻转后再除去前导0
    {
        minNum.length--;
        ii--;
    }

    ii = maxNum.length - 1;
    while (maxNum.numBody[ii] == '0' && ii >= 0)//翻转后再除去前导0
    {
        maxNum.length--;
        ii--;
    }

    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
    {
        //将临时变量长度重置为i
        eachTemp.length = i;
        //进位变量重置为0
        tempJinwei = 0;

        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
        {
            eachTemp.numBody[j - minNum.length + i] =
                    (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) % 10 +
                    '0';
            ++eachTemp.length;
            tempJinwei = (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) / 10;
        }

        //最后的进位处理
        if (tempJinwei > 0)//如果进位大于0
        {
            eachTemp.numBody[eachTemp.length] = tempJinwei + '0';
            ++eachTemp.length;
        }
        //还要再将0加入到临时变量中
        for (int j = 0; j < i; ++j)//
        {
            eachTemp.numBody[j] = '0';
        }
        eachTemp.flag = 1;//临时变量的flag永远是正的
        //先临时把变量字符串翻转一下
        strcpy(eachTemp.numBody, reverseString(eachTemp.numBody, eachTemp.length)); //将a的numBody翻转后给临时变量
        strcpy(returnTemp.numBody, reverseString(returnTemp.numBody, returnTemp.length)); //将a的numBody翻转后给临时变量
        //将临时变量加入总变量
        eachTemp.numBody[eachTemp.length] = '\0';
        if (judgeZero(eachTemp.numBody, eachTemp.length) == 0)//如果变量为0
        {
            eachTemp.length = 0;
            eachTemp.flag = 0;
        }
        returnTemp.numBody[returnTemp.length] = '\0';

        returnSaveTemp = plusUnsignedBigNum(eachTemp, returnTemp);
        //再将结果翻转过来
        strcpy(returnTemp.numBody, reverseString(returnSaveTemp.numBody, returnSaveTemp.length)); //将a的numBody翻转后给临时变量
        //用returnSaveTemp暂存
        returnTemp.length = returnSaveTemp.length;
        returnTemp.flag = returnSaveTemp.flag;
    }

    //判断返回结构体是否为全0
    returnTemp.flag = -1;
    for (int i = 0; i < returnTemp.length; ++i) //
    {
        if (returnTemp.numBody[i] != 0)//一旦有一个不是0
        {
            //flag变量置为1
            returnTemp.flag = 1;
            break;
        }
    }
    if (returnTemp.flag == -1)  //如果flag还是-1
    {
        returnTemp.flag = 0;
    }
    //除去前(后)导0
    for (int i = returnTemp.length - 1; i >= 0; --i) {
        if (returnTemp.numBody[i] != '0') {
            break;
        }
        --returnTemp.length;
    }
    //最后再翻转一下
    strcpy(returnTemp.numBody, reverseString(returnTemp.numBody, returnTemp.length)); //将a的numBody翻转后给临时变量
    //给最后一个元素添加/0表示字符串结束
    if (returnTemp.length >= MAXSIZE)//如果超出，则报溢出，直接退出
    {
        printf("Over Flow!");
        exit(0);//TODO：溢出不直接退出
    }//
    else//
    {
        returnTemp.numBody[returnTemp.length] = '\0';
    }
    return returnTemp;
}


struct SignedBigNum multiplySignedBigNum(struct SignedBigNum a, struct SignedBigNum b)//无符号大数乘法
{
    //初始化变量
    //用于返回的结构体
    struct SignedBigNum returnTemp;
    //初始化返回结构体
    returnTemp.length = 1;
    strcpy(returnTemp.numBody, "0");
    returnTemp.flag = 0;
    if (b.flag == 0 || a.flag == 0)//如果a为0或者b为0
    {
        //结果可以直接返回
        return returnTemp;
    }

    //用于临时记录每一次单位乘法的结果
    struct SignedBigNum eachTemp;
    //临时变量长度初始化为0
    eachTemp.length = 0;
    //用于进位的临时变量
    int tempJinwei;
    //判断出哪个变量更长
    struct SignedBigNum maxNum;
    struct SignedBigNum minNum;
    //临时用于保存结果的变量
    struct SignedBigNum returnSaveTemp;


    //翻转字符串
    if (b.length > a.length)//如果b的长度大于a
    {
        //就把b的值复制给maxNum
        maxNum.length = b.length;
        maxNum.flag = b.flag;
        strcpy(maxNum.numBody, reverseString(b.numBody, b.length)); //将b的numBody翻转后给临时变量

        //把a的值复制给minNum
        minNum.length = a.length;
        minNum.flag = a.flag;
        strcpy(minNum.numBody, reverseString(a.numBody, a.length)); //将a的numBody翻转后给临时变量

    } else//否则
    {
        //就把a的值复制给maxNum
        maxNum.length = a.length;
        maxNum.flag = a.flag;
        strcpy(maxNum.numBody, reverseString(a.numBody, a.length)); //将a的numBody翻转后给临时变量

        //把b的值复制给minNum
        minNum.length = b.length;
        minNum.flag = b.flag;
        strcpy(minNum.numBody, reverseString(b.numBody, b.length)); //将a的numBody翻转后给临时变量

    }

    int ii = minNum.length - 1;
    while (minNum.numBody[ii] == '0' && ii >= 0)//翻转后再除去前导0
    {
        minNum.length--;
        ii--;
    }

    ii = maxNum.length - 1;
    while (maxNum.numBody[ii] == '0' && ii >= 0)//翻转后再除去前导0
    {
        maxNum.length--;
        ii--;
    }

    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
    {
        //将临时变量长度重置为0
        eachTemp.length = i;
        //进位变量重置为0
        tempJinwei = 0;

        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
        {
            eachTemp.numBody[j - minNum.length + i] =
                    (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) % 10 + '0';
            ++eachTemp.length;
            tempJinwei = (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) / 10;
        }

        //最后的进位处理
        if (tempJinwei > 0)//如果进位大于0
        {
            eachTemp.numBody[eachTemp.length] = tempJinwei + '0';
            ++eachTemp.length;
        }
        //还要再将0加入到临时变量中
        for (int j = 0; j < i; ++j)//
        {
            eachTemp.numBody[j] = '0';
        }
        eachTemp.flag = 1;//临时变量的flag永远是正的
        //先临时把变量字符串翻转一下
        strcpy(eachTemp.numBody, reverseString(eachTemp.numBody, eachTemp.length)); //将a的numBody翻转后给临时变量
        strcpy(returnTemp.numBody, reverseString(returnTemp.numBody, returnTemp.length)); //将a的numBody翻转后给临时变量
        //将临时变量加入总变量
        eachTemp.numBody[eachTemp.length] = '\0';
        returnTemp.numBody[returnTemp.length] = '\0';
        returnSaveTemp = plusSignedBigNum(eachTemp, returnTemp);
        //再将结果翻转过来
        strcpy(returnTemp.numBody, reverseString(returnSaveTemp.numBody, returnSaveTemp.length)); //将a的numBody翻转后给临时变量
        //用returnSaveTemp暂存
        returnTemp.length = returnSaveTemp.length;
        returnTemp.flag = returnSaveTemp.flag;
    }

    //判断返回结构体是否为全0
    returnTemp.flag = -1;
    for (int i = 0; i < returnTemp.length; ++i) //
    {
        if (returnTemp.numBody[i] != '0')//一旦有一个不是0
        {
            //flag变量置为1
            returnTemp.flag = 1;
            break;
        }
    }
    if (returnTemp.flag == -1)  //如果flag还是-1
    {
        returnTemp.flag = 0;
    }
    //判断返回结构体的符号
    if (a.flag == -1 && b.flag == -1 || a.flag == 1 && b.flag == 1)//如果都是负数或者正数
    {
        returnTemp.flag = 1;
    } else if (a.flag == -1 && b.flag == 1 || a.flag == 1 && b.flag == -1)//如果有一个为是正数，一个为负数
    {
        returnTemp.flag = -1;
    }

    //最后再翻转一下
    strcpy(returnTemp.numBody, reverseString(returnTemp.numBody, returnTemp.length)); //将a的numBody翻转后给临时变量
    //给最后一个元素添加/0表示字符串结束
    if (returnTemp.length >= MAXSIZE)//如果超出，则报溢出，直接退出
    {
        printf("Over Flow!");
        exit(0);//TODO：溢出不直接退出
    }//
    else//
    {
        returnTemp.numBody[returnTemp.length] = '\0';
    }
    return returnTemp;
}


struct FloatBigNum multiplyFloatBigNum(struct FloatBigNum a, struct FloatBigNum b)//高精度实数大数乘法
{
    //初始化变量
    //用于返回的结构体
    struct FloatBigNum returnTemp;
    //初始化返回结构体
    returnTemp.lengthDecimal = 1;
    returnTemp.lengthInteger = 1;
    strcpy(returnTemp.decimal, "0");
    strcpy(returnTemp.integer, "0");

    returnTemp.flag = 0;
    if (b.flag == 0 || a.flag == 0)//如果a为0或者b为0
    {
        //结果可以直接返回
        return returnTemp;
    }//
    else if (b.lengthDecimal + b.lengthInteger >= MAXSIZE || a.lengthDecimal + a.lengthInteger >= MAXSIZE) {
        returnTemp.flag = -1;
        return returnTemp;
    }

    //用于临时记录每一次单位乘法的结果
    struct FloatBigNum eachTemp;
    //临时变量长度初始化为0
    eachTemp.lengthInteger = 0;
    eachTemp.lengthDecimal = 0;
    //用于进位的临时变量
    int tempJinwei;
    //将实数运算转化成有符号整数运算
    struct SignedBigNum maxNum;
    struct SignedBigNum minNum;
    //用于保存小数的位数
    int maxNumDecimalLength;
    int minNumDecimalLength;
    if (b.lengthDecimal + b.lengthInteger > a.lengthDecimal + a.lengthInteger)//如果b的长度大于a
    {
        //就把b的值复制给maxNum
        maxNum.length = b.lengthDecimal + b.lengthInteger;
        maxNum.flag = b.flag;
        maxNumDecimalLength = b.lengthDecimal;
        //先把小数部分反转后复制进去
        strcpy(maxNum.numBody, reverseString(b.decimal, b.lengthDecimal));
        //再把整数部分反转后复制进去
        for (int i = b.lengthDecimal; i < b.lengthDecimal + b.lengthInteger; ++i) {
            maxNum.numBody[i] = b.integer[b.lengthInteger - 1 - (i - b.lengthDecimal)];
        }

        //把a的值复制给minNum
        minNum.length = a.lengthDecimal + a.lengthInteger;;
        minNum.flag = a.flag;
        //把小数的值保存在临时变量中
        minNumDecimalLength = a.lengthDecimal;
        strcpy(minNum.numBody, reverseString(a.decimal, a.lengthDecimal));
        //再把整数部分反转后复制进去
        for (int i = a.lengthDecimal; i < a.lengthDecimal + a.lengthInteger; ++i) {
            minNum.numBody[i] = a.integer[a.lengthInteger - 1 - (i - a.lengthDecimal)];
        }
    } else//否则
    {
        //就把b的值复制给maxNum
        maxNum.length = a.lengthDecimal + a.lengthInteger;
        maxNum.flag = a.flag;
        //把小数的值保存在临时变量中
        maxNumDecimalLength = a.lengthDecimal;
        //先把小数部分反转后复制进去
        strcpy(maxNum.numBody, reverseString(a.decimal, a.lengthDecimal));
        //再把整数部分反转后复制进去
        for (int i = a.lengthDecimal; i < a.lengthDecimal + a.lengthInteger; ++i) {
            maxNum.numBody[i] = a.integer[a.lengthInteger - 1 - (i - a.lengthDecimal)];
        }

        //把a的值复制给minNum
        minNum.length = b.lengthDecimal + b.lengthInteger;;
        minNum.flag = b.flag;
        minNumDecimalLength = b.lengthDecimal;
        strcpy(minNum.numBody, reverseString(b.decimal, b.lengthDecimal));
        //再把整数部分反转后复制进去
        for (int i = b.lengthDecimal; i < b.lengthDecimal + b.lengthInteger; ++i) {
            minNum.numBody[i] = b.integer[b.lengthInteger - 1 - (i - b.lengthDecimal)];
        }
    }

    //这边可以直接调用有符号整数的乘法
    struct SignedBigNum returnSaveTemp;//用于临时保存有符号数返回的结果

    //需要翻转一下
    strcpy(minNum.numBody, reverseString(minNum.numBody, minNum.length)); //将a的numBody翻转后给临时变量
    strcpy(maxNum.numBody, reverseString(maxNum.numBody, maxNum.length)); //将a的numBody翻转后给临时变量
    returnSaveTemp = multiplySignedBigNum(minNum, maxNum);

    returnTemp.flag = returnSaveTemp.flag;
    returnTemp.lengthDecimal = maxNumDecimalLength + minNumDecimalLength;
    returnTemp.lengthInteger = returnSaveTemp.length - returnTemp.lengthDecimal;
    for (int i = 0; i < returnSaveTemp.length - returnTemp.lengthDecimal; ++i) {
        returnTemp.integer[i] = returnSaveTemp.numBody[i];
    }
    for (int i = returnSaveTemp.length - returnTemp.lengthDecimal; i < returnSaveTemp.length; ++i) {
        returnTemp.decimal[i - returnSaveTemp.length + returnTemp.lengthDecimal] = returnSaveTemp.numBody[i];
    }
    return returnTemp;
}

struct UnsignedBigNum exponentiationUnsignedBigNum(struct UnsignedBigNum a, int power) {
    struct UnsignedBigNum returnTemp;//用于返回变量
    returnTemp.length = 1;
    returnTemp.flag = 1;
    returnTemp.numBody[0] = '1';
    struct UnsignedBigNum returnSaveTemp;//用于保存临时变量

    if (a.flag == 0) {
        returnTemp.flag = 0;
        returnTemp.numBody[0] = '0';
        return returnTemp;
    }
    if (power < 0) //如果是负数则输出错误信息
    {
        printf("抱歉，暂时不支持负数求幂！\n");
        return returnTemp;
    } else if (power == 0)//如果是0则直接返回1
    {
        return returnTemp;
    }

    for (int i = 0; i < power; ++i) {
        returnSaveTemp = multiplyUnsignedBigNum(a, returnTemp);
        strcpy(returnTemp.numBody, returnSaveTemp.numBody);
        returnTemp.flag = returnSaveTemp.flag;
        returnTemp.length = returnSaveTemp.length;
    }

    return returnTemp;
}

struct SignedBigNum exponentiationSignedBigNum(struct SignedBigNum a, int power) {
    struct SignedBigNum returnTemp;//用于返回变量
    returnTemp.length = 1;
    returnTemp.flag = 1;
    returnTemp.numBody[0] = '1';
    struct SignedBigNum returnSaveTemp;//用于保存临时变量

    if (a.flag == 0) {
        returnTemp.flag = 0;
        returnTemp.numBody[0] = '0';
        return returnTemp;
    }
    if (power < 0) //如果是负数则输出错误信息
    {
        printf("抱歉，暂时不支持负数求幂！\n");
        return returnTemp;
    } else if (power == 0)//如果是0则直接返回1
    {
        return returnTemp;
    }

    for (int i = 0; i < power; ++i) {
        returnSaveTemp = multiplySignedBigNum(a, returnTemp);
        strcpy(returnTemp.numBody, returnSaveTemp.numBody);
        returnTemp.flag = returnSaveTemp.flag;
        returnTemp.length = returnSaveTemp.length;
    }

    return returnTemp;
}


struct FloatBigNum exponentiationFloatBigNum(struct FloatBigNum a, int power) {
    struct FloatBigNum returnTemp;//用于返回变量
    returnTemp.lengthDecimal = 1;
    returnTemp.lengthInteger = 1;
    returnTemp.flag = 1;
    returnTemp.integer[0] = '1';
    returnTemp.decimal[0] = '0';
    struct FloatBigNum returnSaveTemp;//用于保存临时变量

    if (a.flag == 0) {
        returnTemp.flag = 0;
        returnTemp.integer[0] = '0';
        return returnTemp;
    }
    if (power < 0) //如果是负数则输出错误信息
    {
        printf("抱歉，暂时不支持负数求幂！\n");
        return returnTemp;
    } else if (power == 0)//如果是0则直接返回1
    {
        return returnTemp;
    }

    for (int i = 0; i < power; ++i) {
        returnSaveTemp = multiplyFloatBigNum(a, returnTemp);
        strcpy(returnTemp.integer, returnSaveTemp.integer);
        strcpy(returnTemp.decimal, returnSaveTemp.decimal);
        returnTemp.flag = returnSaveTemp.flag;
        returnTemp.lengthDecimal = returnSaveTemp.lengthDecimal;
        returnTemp.lengthInteger = returnSaveTemp.lengthInteger;
    }

    return returnTemp;
}

struct UnsignedBigNum factorialUnsignedBigNum(int factorialNum) {//只有非负数才能有阶乘
    struct UnsignedBigNum returnTemp;//用于返回变量
    struct UnsignedBigNum returnSaveTemp1, returnSaveTemp2;//用于保存临时变量
    struct UnsignedBigNum tempOne;

    tempOne.length = 1;
    tempOne.numBody[0] = '1';
    tempOne.numBody[1] = '\0';
    tempOne.flag = 1;
    returnTemp.length = 1;
    returnTemp.flag = 1;
    returnTemp.numBody[0] = '1';
    returnSaveTemp1.length = 1;
    returnSaveTemp1.flag = 1;
    returnSaveTemp1.numBody[0] = '2';

    if (factorialNum == 0 || factorialNum < 0) {
        printf("负数不支持阶乘！");
        return returnTemp;
    } else if (factorialNum == 1) {
        return returnTemp;
    } else {
        for (int i = 0; i < factorialNum - 1; ++i) {
            returnSaveTemp2 = multiplyUnsignedBigNum(returnSaveTemp1, returnTemp);
            strcpy(returnTemp.numBody, returnSaveTemp2.numBody);
            returnTemp.flag = returnSaveTemp2.flag;
            returnTemp.length = returnSaveTemp2.length;
            returnSaveTemp1.numBody[returnSaveTemp1.length]='\0';

            returnSaveTemp1 = plusUnsignedBigNum(returnSaveTemp1, tempOne);//加一
        }
    }

    return returnTemp;
}

