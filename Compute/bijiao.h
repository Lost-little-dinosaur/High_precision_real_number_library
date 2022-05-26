#include<stdio.h>
#include<string.h>
//
// Created by Dinosaur on 2022/5/23.
//
//#include "../Model/struct.h"
#include "string.h"
//#include "plusUnsigndBigNum.h"

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM


struct SigndBigNum {//有符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，-1则为负数、1则为正数、0则表示原数为0
};

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_STRUCT_H

struct SigndBigNum totalcompare( SigndBigNum x,SigndBigNum y){
    if(x.flag>y.flag){
        return x;
    }
    else if(x.flag<y.flag){
        return y;
    }
    else{
        calculate(x,y);
    }

    int main() {
        char a[1005],b[1005];
        SigndBigNum x,y,r;
        UnsigndBignNum c,d;
        scanf("%s",&a);
        scanf("%s",&b);
        x.flag= judgeSigndBigNum(a);
        y.flag= judgeSigndBigNum(b);

        //printf("flag=%d %d\n",x.flag,y.flag);

        x.length= strlen(a)-1;
        y.length= strlen(b)-1;
        c=removeSigndBigNumFlag(a);
        d= removeSigndBigNumFlag(b);
        strcpy(x.numBody,c.numBody);
        strcpy(y.numBody,d.numBody);

        /* printf("%s ",x.numBody);
         printf("%s \n",y.numBody);*/


    }

    int Scanf (char num[])
    {
        int len=strlen(num);
        int i;
        for(i=0; i<len; i++)
            if(num[i]=='.')
                break;
        return i;
    }
    char calculate(SigndBigNum x,SigndBigNum y/*char num1[],char num2[]*/)
    {

        if(x.length>y.length){
            return x;
            else if(x.length<y.length){
                return y;
                else if(x.length1=y.length){
                    zhuwei(x,y);
                }
            }


            int zhuwei(char num1[],char num2[],int length)
            {
                int i,j;
                for(i=0; i<length; i++)
                {
                    if(num1[i]!=num2[i])
                        break;
                }
                int sum=num1[i]-num2[i];
                if(sum>0){
                    return num1;
                }
                else if(sum<0){
                    return num2;
                }
                else if(sum=0){
                    return num1;
                }
            }
#include<stdio.h>
#include<string.h>
            int gps(char num[])//找到小数点所在的位置
            {
                struct SigndBigNum a;

                int len=strlen(num);
                int i;
                for(i=0; i<len; i++)
                    if(num[i]=='.')
                        break;
                return i;
            }
            int cmp1(char num1[],char num2[])//比较小数点的大小
            {
                int len=gps(num1);
                return strcmp(num1+len,num2+len);
            }
            int cmp(char num1[],char num2[],int len)//比较大数的大小
            {
                int i;
                for(i=0; i<len; i++)
                {
                    if(num1[i]!=num2[i])
                        break;
                }
                int sum=num1[i]-num2[i];
                if(i!=len)
                    return sum;
                return 0;
            }
