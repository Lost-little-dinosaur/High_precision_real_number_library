//
// Created by Dinosaur on 2022/5/23.
//
#include "plusUnsigndBigNum.h"
#include "string.h"
#include "../Model/struct.h"

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYSIGNBIGNUM
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYSIGNBIGNUM

struct SigndBigNum multiplySigndBignNum(struct SigndBigNum a, struct SigndBigNum b)//无符号大数乘法
{
    if (a.flag == 0)//如果a为0
    {
        //结果可以直接返回b
        return b;
    }
    if (b.flag == 0)//如果a为0
    {
        //结果可以直接返回a
        return a;
    }

    //初始化变量
    //用于返回的结构体
    struct SigndBigNum retuenTemp;
    //用于临时记录每一次单位乘法的结果
    struct SigndBigNum eachTemp;
    //临时变量长度初始化为0
    eachTemp.length = 0;
    //用于进位的临时变量
    int tempJinwei;
    //判断出哪个变量更长
    struct SigndBigNum maxNum;
    struct SigndBigNum minNum;
    if (b.length > a.length)//如果b的长度大于a
    {
        //就把b的值复制给maxNum
        maxNum.length = b.length;
        maxNum.flag = b.flag;
        strcpy(maxNum.numBody, b.numBody);
        //把a的值复制给minNum
        minNum.length = a.length;
        minNum.flag = a.flag;
        strcpy(minNum.numBody, a.numBody);

    } else//否则
    {
        //就把a的值复制给maxNum
        maxNum.length = a.length;
        maxNum.flag = a.flag;
        strcpy(maxNum.numBody, a.numBody);
        //把b的值复制给minNum
        minNum.length = b.length;
        minNum.flag = b.flag;
        strcpy(minNum.numBody, b.numBody);
    }

    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
    {
        //将临时变量长度重置为0
        eachTemp.length = 0;
        //进位变量重置为0
        tempJinwei = 0;

        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
        {
            eachTemp.numBody[i] = (tempJinwei + '0') + (a.numBody[j] - '0') * (b.numBody[i] - '0') % 10 + '0';
            tempJinwei = (a.numBody[j] - '0') * (b.numBody[i] - '0') / 10;
        }

        //最后的进位处理
        if (tempJinwei > 0)//如果进位大于0
        {
            eachTemp.numBody[minNum.length + maxNum.length] = tempJinwei;
        }
        //还要再将0加入到临时变量中
        for (int j = 0; j < i; ++j) //
        {
            eachTemp.numBody[j] = '0';
        }
        //将临时变量加入总变量
        strcpy(retuenTemp.numBody, plusUnsigndBigNum(eachTemp.numBody, retuenTemp.numBody));
    }

    //判断返回结构体的符号
    if (a.flag == -1 && b.flag == -1 || a.flag == 1 && b.flag == 1)//如果都是负数或者正数
    {
        retuenTemp.flag = 1;
    } else if (a.flag == -1 && b.flag == 1 || a.flag == 1 && b.flag == -1)//如果有一个为是正数，一个为负数
    {
        retuenTemp.flag = -1;
    }

    return retuenTemp;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYSIGNBIGNUM
