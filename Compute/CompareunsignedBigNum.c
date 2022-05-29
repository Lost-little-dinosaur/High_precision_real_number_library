//
// Created by DELL on 2022/5/29.
//

#include<stdio.h>
#include<string.h>
#include"../Utils/removeSigndBigNumFlag.h"
#include "../Model/struct.h"
//
// Created by Dinosaur on 2022/5/23.
//
//#include "../Model/struct.h"
#include "string.h"
//#include "plusUnsigndBigNum.h"

#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_MULTIPLYUNSIGNBIGNUM
#define MAXSIZE 500
/*typedef struct UnsignedBigNum {//无符号大整数
    int length;//表示数据的位数
    char numBody[MAXSIZE];//表示数据主体
    int flag;//表示符号，1则为、0则表示原数为0
}UnsignedBigNum;
*/

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_STRUCT_H


/*int Scanf (char num[])
{
    int len=strlen(num);
    int i;
    for(i=0; i<len; i++)
        if(num[i]=='.')
            break;
    return i;
}*/

UnsignedBigNum zhuwei(UnsignedBigNum  x,UnsignedBigNum y){
    int i,j;
    for(i=0; i<x.length; i++)
    {
        if(x.numBody[i]!=y.numBody[i])
            break;
    }
    int sum=x.numBody[i]-y.numBody[i];
    if(sum * x.flag>0){
        return x;
    }
    else if(sum * x.flag<0){
        return y;
    }
    else if(sum=0){
        return x;
    }

}
UnsignedBigNum calculate(  UnsignedBigNum x, UnsignedBigNum y) {


        if (x.length * x.flag > y.length * y.flag) {
            return x;
        } else if (x.length * x.flag < y.length * y.flag) {
            return y;
        } else if (x.length * x.flag == y.length * y.flag) {
            zhuwei(x, y);
        }
    }
UnsignedBigNum totalcompare( UnsignedBigNum x, UnsignedBigNum y) {
    if (x.flag > y.flag) {
        return x;
    } else if (x.flag < y.flag) {
        return y;
    } else {
        calculate(x, y);
    }
}



int gps(char num[])//找到小数点所在的位置(这能算是没有小数点的话遍历全部吗）
{


    int len=strlen(num);
    int i;
    for(i=0; i<len; i++)
        if(num[i]=='.')
            break;
    return i;
}/*
int cmp1(char num1[],char num2[])//比较小数点的大小
{
    int len=gps(num1);
    return strcmp(num1+len,num2+len);
}*/
/* int cmp(char num1[],char num2[],int len)//比较大数的大小
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
 }*/
int main(){
    char a[1005],b[1005];
    struct UnsignedBigNum x,y;
    scanf("%s",&a);
    scanf("%s",&b);
    x.length= gps(a);
    y.length= gps(b);
    x.numBody;
    y.numBody;
    /*x.flag= judgeUnsigndBigNum(a);
    y.flag= judgeUnigndBigNum(b);*/

}
