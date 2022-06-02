//
// Created by sherlock on 2022/6/2.
//

#include "compare.h"
#include "..\Model\struct.h"
#include <string.h>

char* cmp_removezero(char x[])  //消除前导零
{
    int len = strlen(x);
    int pos = 0;
    for(pos = 0;pos < len;pos++){
        if(x[pos] != '0')
        {
            break;
        }
    }
    return (x + pos);
}

int int_compare(char a[],char b[])     //比较字符串的大小
{
    int lena,lenb,i;
    strcpy(a,cmp_removezero(a));
    strcpy(b,cmp_removezero(b));
    lena = strlen(a);
    lenb = strlen(b);
    if(lena < lenb)
    {
        return -1;      //a的长度比b小，返回-1
    }
    else if(lena > lenb)
    {
        return 1;       //a长度大于b，返回1
    }
    else
    {
        if(strcmp(a,b) == 0)    //相等
            return 0;
        else
        {
            for(i = 0;i < lena;i++)
            {
                if(a[i] > b[i])
                    return 1;
                if(a[i] < b[i])
                    return -1;
            }
            return 0;
        }
    }
}

int float_compare(char a[],char b[])
{
    return strcmp(a,b);
}

int compareUnsignedBigNum(UnsignedBigNum a,UnsignedBigNum b)
{
    return int_compare(a.numBody,b.numBody);
}

int compareSignedBigNum(SignedBigNum a,SignedBigNum b)
{
    if(a.flag != b.flag)  //符号不同，正数比负数大
    {
        if(a.flag > b.flag)
        {
            return 1;
        }
        else if(a.flag < b.flag)
        {
            return -1;
        }
    }
    else   //符号相同
    {
        if(a.flag == 0)
        {
            return 0;
        }
        else if(a.flag == 1) //正数，绝对值大的大
        {
           return int_compare(a.numBody,b.numBody);
        }
        else   //负数，绝对值小的大
        {
            return int_compare(b.numBody,a.numBody);
        }
    }
}


int compareFloatBigNum(FloatBigNum a,FloatBigNum b)
{
    if(a.flag != b.flag) //符号不同，正数大于负数
    {
        if(a.flag > b.flag)
        {
            return 1;
        }
        else if(a.flag < b.flag)
        {
            return -1;
        }
    }
    else  //符号相同
    {
        if(a.flag == 0)
        {
            return 0;
        }
        else if(a.flag == 1)  //都为正数，绝对值大的大
        {
            //先比较整数部分
            if(int_compare(a.integer,b.integer) == 1)
            {
                return 1;
            }
            else if(int_compare(a.integer,b.integer) == -1)
            {
                return -1;
            }
            else  //整数部分相同，比小数部分
            {
                return float_compare(a.decimal,b.decimal);
            }
        }
        else  //负数，绝对值小的大
        {
            //先比整数
            if(int_compare(a.integer,b.integer) == 1)
            {
                return -1;
            }
            else if(int_compare(a.integer,b.integer) == -1)
            {
                return 1;
            }
            else  //整数相同，比小数
            {
                return -float_compare(a.decimal,b.decimal);
            }
        }
    }
}
