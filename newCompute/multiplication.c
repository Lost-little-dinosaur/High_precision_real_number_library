//
// Created by Dinosaur on 2022/5/27.
//

#include "multiplication.h"
#include "../Model/struct.h"
#include "plus.h"
#include "string.h"

struct UnsignedBigNum multiplyUnsignedBigNum(struct UnsignedBigNum a, struct UnsignedBigNum b)//无符号大数乘法
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
    struct UnsignedBigNum returnTemp;
    //初始化返回结构体
    returnTemp.length = 1;
    strcpy(returnTemp.numBody, "0");
    returnTemp.flag = 1;
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
    if (b.length > a.length)//如果b的长度大于a
    {
        //就把b的值复制给maxNum
        maxNum.length = b.length;
        maxNum.flag = b.flag;
        for (int i = 0; i < b.length; ++i) //将b的numBody翻转后给临时变量
        {
            maxNum.numBody[b.length - i - 1] = b.numBody[i];
        }

        //把a的值复制给minNum
        minNum.length = a.length;
        minNum.flag = a.flag;
        for (int i = 0; i < a.length; ++i) //将b的numBody翻转后给临时变量
        {
            minNum.numBody[a.length - i - 1] = a.numBody[i];
        }
    } else//否则
    {
        //就把a的值复制给maxNum
        maxNum.length = a.length;
        maxNum.flag = a.flag;
        for (int i = 0; i < a.length; ++i) //将b的numBody翻转后给临时变量
        {
            maxNum.numBody[a.length - i - 1] = a.numBody[i];
        }

        //把b的值复制给minNum
        minNum.length = b.length;
        minNum.flag = b.flag;
        for (int i = 0; i < b.length; ++i) //将b的numBody翻转后给临时变量
        {
            minNum.numBody[b.length - i - 1] = b.numBody[i];
        }
    }

    int ii = minNum.length - 1;
    while (minNum.numBody[ii] == 0 && ii >= 0)//翻转后再除去前导0
    {
        minNum.length--;
        ii--;
    }

    ii = maxNum.length - 1;
    while (maxNum.numBody[ii] == 0 && ii >= 0)//翻转后再除去前导0
    {
        maxNum.length--;
        ii--;
    }

    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
    {
        //将临时变量长度重置为0
        eachTemp.length = 0;
        //进位变量重置为0
        tempJinwei = 0;

        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
        {
            eachTemp.numBody[j - minNum.length + i] =
                    (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) % 10 +
                    '0';
            tempJinwei = (tempJinwei + (maxNum.numBody[j - minNum.length] - '0') * (minNum.numBody[i] - '0')) / 10;
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
        strcpy(returnTemp.numBody, plusUnsignedBigNum(eachTemp, returnTemp).numBody);
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
    return returnTemp;
}

//
//struct SignedBigNum multiplySignedBigNum(struct SignedBigNum a, struct SignedBigNum b)//无符号大数乘法
//{
//    if (a.flag == 0)//如果a为0
//    {
//        //结果可以直接返回b
//        return b;
//    }
//    if (b.flag == 0)//如果a为0
//    {
//        //结果可以直接返回a
//        return a;
//    }
//
//    //初始化变量
//    //用于返回的结构体
//    struct SignedBigNum returnTemp;
//    //用于临时记录每一次单位乘法的结果
//    struct SignedBigNum eachTemp;
//    //临时变量长度初始化为0
//    eachTemp.length = 0;
//    //用于进位的临时变量
//    int tempJinwei;
//    //判断出哪个变量更长
//    struct SignedBigNum maxNum;
//    struct SignedBigNum minNum;
//    if (b.length > a.length)//如果b的长度大于a
//    {
//        //就把b的值复制给maxNum
//        maxNum.length = b.length;
//        maxNum.flag = b.flag;
//        strcpy(maxNum.numBody, b.numBody);
//        //把a的值复制给minNum
//        minNum.length = a.length;
//        minNum.flag = a.flag;
//        strcpy(minNum.numBody, a.numBody);
//
//    } else//否则
//    {
//        //就把a的值复制给maxNum
//        maxNum.length = a.length;
//        maxNum.flag = a.flag;
//        strcpy(maxNum.numBody, a.numBody);
//        //把b的值复制给minNum
//        minNum.length = b.length;
//        minNum.flag = b.flag;
//        strcpy(minNum.numBody, b.numBody);
//    }
//
//    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
//    {
//        //将临时变量长度重置为0
//        eachTemp.length = 0;
//        //进位变量重置为0
//        tempJinwei = 0;
//
//        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
//        {
//            eachTemp.numBody[i] = (tempJinwei + '0') + (a.numBody[j] - '0') * (b.numBody[i] - '0') % 10 + '0';
//            tempJinwei = (a.numBody[j] - '0') * (b.numBody[i] - '0') / 10;
//        }
//
//        //最后的进位处理
//        if (tempJinwei > 0)//如果进位大于0
//        {
//            eachTemp.numBody[minNum.length + maxNum.length] = tempJinwei;
//        }
//        //还要再将0加入到临时变量中
//        for (int j = 0; j < i; ++j) //
//        {
//            eachTemp.numBody[j] = '0';
//        }
//        //将临时变量加入总变量
//        strcpy(returnTemp.numBody, plusUnsigndBigNum(eachTemp, returnTemp).n);
//    }
//
//    //判断返回结构体的符号
//    if (a.flag == -1 && b.flag == -1 || a.flag == 1 && b.flag == 1)//如果都是负数或者正数
//    {
//        returnTemp.flag = 1;
//    } else if (a.flag == -1 && b.flag == 1 || a.flag == 1 && b.flag == -1)//如果有一个为是正数，一个为负数
//    {
//        returnTemp.flag = -1;
//    }
//
//    return returnTemp;
//}
//
//
//struct SignedBigNum multiplyFloatBigNum(struct SignedBigNum a, struct SignedBigNum b)//高精度实数大数乘法
//{
//    if (a.flag == 0)//如果a为0
//    {
//        //结果可以直接返回b
//        return b;
//    }
//    if (b.flag == 0)//如果a为0
//    {
//        //结果可以直接返回a
//        return a;
//    }
//
//    //初始化变量
//    //用于返回的结构体
//    struct SignedBigNum returnTemp;
//    //用于临时记录每一次单位乘法的结果
//    struct SignedBigNum eachTemp;
//    //临时变量长度初始化为0
//    eachTemp.length = 0;
//    //用于进位的临时变量
//    int tempJinwei;
//    //判断出哪个变量更长
//    struct SignedBigNum maxNum;
//    struct SignedBigNum minNum;
//    if (b.length > a.length)//如果b的长度大于a
//    {
//        //就把b的值复制给maxNum
//        maxNum.length = b.length;
//        maxNum.flag = b.flag;
//        strcpy(maxNum.numBody, b.numBody);
//        //把a的值复制给minNum
//        minNum.length = a.length;
//        minNum.flag = a.flag;
//        strcpy(minNum.numBody, a.numBody);
//
//    } else//否则
//    {
//        //就把a的值复制给maxNum
//        maxNum.length = a.length;
//        maxNum.flag = a.flag;
//        strcpy(maxNum.numBody, a.numBody);
//        //把b的值复制给minNum
//        minNum.length = b.length;
//        minNum.flag = b.flag;
//        strcpy(minNum.numBody, b.numBody);
//    }
//
//    for (int i = 0; i < minNum.length; ++i)//开始遍历b，进行单次乘法
//    {
//        //将临时变量长度重置为0
//        eachTemp.length = 0;
//        //进位变量重置为0
//        tempJinwei = 0;
//
//        for (int j = minNum.length; j < minNum.length + maxNum.length; ++j) //开始遍历a，进行单次乘法的细致步骤
//        {
//            eachTemp.numBody[i] = (tempJinwei + '0') + (a.numBody[j] - '0') * (b.numBody[i] - '0') % 10 + '0';
//            tempJinwei = (a.numBody[j] - '0') * (b.numBody[i] - '0') / 10;
//        }
//
//        //最后的进位处理
//        if (tempJinwei > 0)//如果进位大于0
//        {
//            eachTemp.numBody[minNum.length + maxNum.length] = tempJinwei;
//        }
//        //还要再将0加入到临时变量中
//        for (int j = 0; j < i; ++j) //
//        {
//            eachTemp.numBody[j] = '0';
//        }
//        //将临时变量加入总变量
//        strcpy(returnTemp.numBody, plusSignedBigNum(eachTemp, returnTemp).numBody);
//    }
//
//    //判断返回结构体的符号
//    if (a.flag == -1 && b.flag == -1 || a.flag == 1 && b.flag == 1)//如果都是负数或者正数
//    {
//        returnTemp.flag = 1;
//    } else if (a.flag == -1 && b.flag == 1 || a.flag == 1 && b.flag == -1)//如果有一个为是正数，一个为负数
//    {
//        returnTemp.flag = -1;
//    }
//
//    return returnTemp;
//}
