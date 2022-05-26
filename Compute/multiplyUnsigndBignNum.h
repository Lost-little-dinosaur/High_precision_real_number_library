//
// Created by Dinosaur on 2022/5/23.
//
#include "../Model/struct.h"
#include "string.h"
#include "plusUnsigndBigNum.h"

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM

struct UnsignedBigNum multiplyUnsigndBigNum(struct UnsignedBigNum a, struct UnsignedBigNum b)//无符号大数乘法
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
    struct UnsignedBigNum retuenTemp;
    //用于临时记录每一次单位乘法的结果
    struct UnsignedBigNum eachTemp;
    //临时变量长度初始化为0
    eachTemp.length = 0;
    //用于进位的临时变量
    int tempJinwei;
    //判断出哪个变量更长
    struct UnsignedBigNum maxNum;
    struct UnsignedBigNum minNum;

    //翻转字符串
    int len = 0;
    char* p = a.numBody;
    while (*p != 0)//
    {
        len++;
        p++;
    }
    // 交换 ...
    int ii = 0;
    char c;
    while (ii <= len / 2 - 1)//
    {
        c = *(a.numBody + ii);
        *(a.numBody + ii) = *(a.numBody + len - 1 - ii);
        *(a.numBody + len - 1 - ii) = c;
        ii++;
    }
    len = 0;
     p = b.numBody;
    while (*p != 0)//
    {
        len++;
        p++;
    }
    // 交换 ...
    ii = 0;
    while (ii <= len / 2 - 1)//
    {
        c = *(b.numBody + ii);
        *(b.numBody + ii) = *(b.numBody + len - 1 - ii);
        *(b.numBody + len - 1 - ii) = c;
        ii++;
    }

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
        for (int j = 0; j < i; ++j)//
        {
            eachTemp.numBody[j] = '0';
        }
        //将临时变量加入总变量
        strcpy(retuenTemp.numBody, plusUnsigndBigNum(eachTemp.numBody, retuenTemp.numBody));
    }

    //判断返回结构体是否为全0
    retuenTemp.flag = -1;
    for (int i = 0; i < retuenTemp.length; ++i) //
    {
        if (retuenTemp.numBody[i] != 0)//一旦有一个不是0
        {
            //flag变量置为1
            retuenTemp.flag = 1;
            break;
        }
    }
    if (retuenTemp.flag == -1)  //如果flag还是-1
    {
        retuenTemp.flag = 0;
    }
    return retuenTemp;
}

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM
