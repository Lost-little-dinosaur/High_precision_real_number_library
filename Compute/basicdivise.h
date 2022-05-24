//
// Created by Sherlock on 2022/5/19.
//
#ifndef HIGH_PRECISION_REAL_NUMBER_LIBRARY_BASICDIVISE_H
#define HIGH_PRECISION_REAL_NUMBER_LIBRARY_BASICDIVISE_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char dividend[10001],divisor[10001];   //定义全局变量供下面的程序使用
char arr[1000000],ans[1000000];    //ans用于储存计算结果，arr储存余数

int Compare(char a[],char b[])     //比较字符串的大小
{
    int lena,lenb,i;
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

int judge(char ch[])         //判断字符串ch是否全为0，若全为0，返回1，否则返回0
{
    int i,len;
    len = strlen(ch);
    for(i = 0;i < len;i++)
    {
        if(ch[i] != '0')
        {
            return 0;
        }
    }
    return 1;
}

void Sub(char a1[],char b1[])    //a1为被减数，b1为减数
{
    int lena,lenb,i,len;
    int a[1000] = {0},b[1000] = {0},d[1000]= {0};
    lena = strlen(a1);
    lenb = strlen(b1);
    for(i = 0;i < lena;i++)  a[i] = a1[lena - 1 - i] - '0';
    for(i = 0;i < lenb;i++)  b[i] = b1[lenb - 1 - i] - '0';
    len = lena > lenb ? lena:lenb;
    for(i = 0;i < len;i++)    //相减
    {
        if(a[i] < b[i])    //若被减数不够减，向高位借位
        {
            a[i + 1]--;
            d[i] = a[i] - b[i] + 10;
        }
        else
        {
            d[i] = a[i] - b[i];
        }
    }
    //去除高位0
    if(!d[i - 1])
    {
      len--;
      //i--;
    }
    //将结果转化为字符逆着赋给数组ans
    for(i = 0;i < len;i++)
    {
        ans[i] = d[len - i - 1] + '0';
    }
    //if(judge(ans))//若差全为0，则只输出一个
      //  strcpy(ans,"0");
}

char* divise(char ina[],char inb[])
{
    strcpy(dividend,ina);
    strcpy(divisor,inb);
    char *p;
    char tmp[1000],t[1000];    //tmp储存被除数片段
    int lens,lent,i,j,k,flag = 0;
    memset(arr,0,sizeof(arr));
    if(judge(divisor))
    {
        p = "除数不能为0!";
        return p;
    }

    if(Compare(dividend,divisor) < 0)   //若被除数小于除数，则商为0，余数为被除数
        strcpy(arr,dividend);
    else if(!Compare(dividend,divisor)) //若两数相等，则商为1，余数为0
        ans[0] = '1';
    else         //若被除数大于除数
    {
        j = lent = 0;
        lens = strlen(dividend);
        memset(tmp,0,sizeof(tmp));
        memset(t,0,sizeof(t));
        for(i = 0;i < lens;i++)   //得到被除数切片,得到整型数组形式的商
        {                      //t的一个元素表示一次相除的商
            //printf("i = %d,j = %d\n",i,j);
            tmp[j++] = dividend[i];
            flag = 0;
            //printf("tmp = %s\n",tmp);
            while(Compare(tmp,divisor) >= 0)    //可以除
            {//用减法获得对应位置的商
                Sub(tmp,divisor);
                strcpy(tmp,ans);
                //printf("new tmp = %s\n",tmp);
                memset(ans,0,sizeof(ans));
                t[lent]++;
                //printf("%d:lent = %d,%s\n",i,lent,t);
                flag=1;            //对应位置有值
            }
            if(flag)               //将商转换为字符
                t[lent] += '0';
            else                  //对应处无值，即商为0
               t[lent] = '0';
            //printf("t[%d] = %c\n",lent,t[lent] );
            if(tmp[0] == '0') strcpy(tmp,tmp+1);    //消去首位0
            if(!strcmp(tmp,"0"))     //若tmp为'0'
                j = 0;
            else             //继续在b的后面加值
                j = strlen(tmp);
            lent++;
        }
        k = 0;
        for(i = 0;i < lent;i++)
        {
            if(t[i] != '0')
                break;           //找到t数组中第一个不为0的位置
        }
        for(j = i;j < lent;j++)
        {
            ans[k++] = t[j];
        }
        strcpy(arr,tmp);
    }
    //if(judge(ans))
      //  strcpy(ans,"0");
    if(judge(arr))
        strcpy(arr,"0");
    p = ans;
    return p;
}

int hasremindor(char a[],char b[])    //判断是否有余数
{
  divise(a,b);
  if(Compare(arr,"0"))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

char* modulo(char a[],char b[])
{
  divise(a,b);
  char *p;
  p = arr;
  return p;
}
/*
int main(){
  char a[20],b[20];
  scanf("%s%s",a,b);
  printf("%s",divise(a,b));
}
*/

#endif //HIGH_PRECISION_REAL_NUMBER_LIBRARY_BASICDIVISE_H
