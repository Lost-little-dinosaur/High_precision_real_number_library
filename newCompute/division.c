//
// Created by sherlock on 2022/5/29.
//

#include "division.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "..\Model\struct.h"


/*
 * 函数主要实现三种大数数据类型的除法：
 * 无符号整数，有符号整数，浮点数
 * 其中，浮点数可以选择保留的 小数位数
 */

/*
 * 接下来的功能利用数组实现基本的高精度除法运算
 * 之后的三种数据类型的除法调用此基本模型
 */

char dividend[10001],divisor[10001];   //定义全局变量供下面的程序使用
char arr[1000000],ans[1000000];    //ans用于储存计算结果，arr储存余数
int declen;


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

char* divise_int(char ina[],char inb[])
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
    {
        strcpy(arr,dividend);
        strcpy(ans,"0");
    }
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

char* modulo(char a[],char b[])
{
    divise_int(a,b);
    char *p;
    p = arr;
    return p;
}

void setpercision(){
    printf("请设置小数的精度（20~500）：\n");
    scanf("%d",&declen);
}

char* divise_dec(char ina[],char inb[])
{
    char *c ;
    c = modulo(ina,inb);
    memset(ans,0,sizeof(ans));
    strcpy(dividend,c);
    strcpy(divisor,inb);
    for(int i = strlen(dividend);i < declen - 1;i++){
        dividend[i] = '0';
    }
    char *p;
    char tmp[1000],t[1000];    //tmp储存被除数片段
    int lens,lent,i,j,k,flag = 0;
    memset(arr,0,sizeof(arr));
    if(judge(divisor))
    {
        p = "除数不能为0!";
        return p;
    }

    j = lent = 0;
    lens = strlen(dividend);
    memset(tmp,0,sizeof(tmp));
    memset(t,0,sizeof(t));
    //printf("%s %s\n",dividend,divisor);
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
        if(tmp[0] == '0') strcpy(tmp,tmp+1);
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

    //if(judge(ans))
    //  strcpy(ans,"0");
    if(judge(arr))
        strcpy(arr,"0");
    p = ans;
    return p;
}

void reset()
{
    memset(dividend,0,sizeof(dividend));
    memset(divisor,0, sizeof(divisor));
    memset(arr,0, sizeof(arr));
    memset(ans,0, sizeof(ans));
    declen = 0;
}

char* combine(char _int[],char _dec[])
{
    char *all;
    char num[1005];
    strcpy(num,_int);
    for(int i = strlen(_int);i < strlen(_int) + strlen(_dec);i++)
    {
        num[i] = _dec[i - strlen(_int)];
    }
    all = num;
    return all;
}



/*
 * 接下来开始利用构造好的除法模板进行三种除法类型的实现
 */


//无符号整数
UnsignedBigNum DiviseUnsignedBigNum(UnsignedBigNum a,UnsignedBigNum b)
{
    UnsignedBigNum c;
    if(a.flag == 0)
    {
        c.flag = 0;
        strcpy(c.numBody,"0");
        c.length = 0;
        return c;
    }
    strcpy(c.numBody,divise_int(a.numBody,b.numBody));
    c.length = strlen(c.numBody);
    c.flag = 1;
    reset();
    return c;
}


//有符号整数
SignedBigNum DiviseSignedBigNum(SignedBigNum a,SignedBigNum b)
{
    SignedBigNum c;
    c.flag = a.flag * b.flag;
    if(a.flag == 0)
    {
        c.flag = 0;
        strcpy(c.numBody,"0");
        c.length = 0;
        return c;
    }
    strcpy(c.numBody,divise_int(a.numBody,b.numBody));
    c.length = strlen(c.numBody);
    reset();
    return c;
}

//浮点数
FloatBigNum DiviseFloatBigNum(FloatBigNum a,FloatBigNum b)
{
    FloatBigNum c;
    c.flag = a.flag * b.flag;
    if(a.flag == 0)
    {
        c.flag = 0;
        strcpy(c.intager,"0");
        strcpy(c.decimal,"0");
        c.lengthIntager = 0;
        c.lengthDecimal = 0;
        return c;
    }
    char stra[1005],strb[1005];
    strcpy(stra, combine(a.intager,a.decimal));
    strcpy(strb, combine(b.intager,b.decimal));
    strcpy(c.intager,divise_int(stra,strb));
    setpercision();
    strcpy(c.decimal, divise_dec(stra,strb));
    c.lengthIntager = strlen(c.intager);
    c.lengthDecimal = strlen(c.decimal);
    return c;
}


/*
 * 测试代码
 */
/*
int main()
{
    system("chcp 65001");

    UnsignedBigNum a1,b1,c1;
    scanf("%s%s",a1.numBody,b1.numBody);
    c1 = DiviseUnsignedBigNum(a1,b1);
    printf("c1 length = %d\n",c1.length);
    printf("c1 flag = %d\n",c1.flag);
    printf("c1 = %s\n",c1.numBody);

    SignedBigNum a2,b2,c2;
    scanf("%s%s",a2.numBody,b2.numBody);
    a2.flag = -1;
    b2.flag = 1;
    c2 = DiviseSignedBigNum(a2,b2);
    printf("c2 length = %d\n",c2.length);
    printf("c2 flag = %d\n",c2.flag);
    printf("c2 = %s\n",c2.numBody);

    FloatBigNum a3,b3,c3;
    scanf("%s%s%s%s",a3.intager,a3.decimal,b3.intager,b3.decimal);
    a3.flag = 1;
    b3.flag = 1;
    c3 = DiviseFloatBigNum(a3,b3);
    printf("c3 length = %d\n",c3.lengthIntager + c3.lengthDecimal);
    printf("c3 flag = %d\n",c3.flag);
    printf("c3 = %s.%s\n",c3.intager,c3.decimal);
    /*
    char a4_int[20],a4_dec[20],b4_int[20],b4_dec[20],a4[40],b4[40];
    scanf("%s%s%s%s",a4_int,a4_dec,b4_int,b4_dec);
    strcpy(a4, combine(a4_int,a4_dec));
    strcpy(b4, combine(b4_int,b4_dec));
    printf("%s\n%s",a4,b4);

}
*/
