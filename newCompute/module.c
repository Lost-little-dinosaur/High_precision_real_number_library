//
// Created by hang on 2022/5/31.
//

#include "module.h"
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
 * 接下来的功能利用数组实现基本的高精度取模运算
 * 之后的两种数据类型的取模调用此基本模型
 */

char modulo_dividend[1000001], modulo_divisor[1000001];   //定义全局变量供下面的程序使用
char modulo_arr[1000000], modulo_ans[1000000];    //ans用于储存计算结果，arr储存余数
int modulo_declen;


int modulo_Compare(char a[], char b[])     //比较字符串的大小
{
    int lena, lenb, i;
    lena = strlen(a);
    lenb = strlen(b);
    if (lena < lenb) {
        return -1;      //a的长度比b小，返回-1
    } else if (lena > lenb) {
        return 1;       //a长度大于b，返回1
    } else {
        if (strcmp(a, b) == 0)    //相等
            return 0;
        else {
            for (i = 0; i < lena; i++) {
                if (a[i] > b[i])
                    return 1;
                if (a[i] < b[i])
                    return -1;
            }
            return 0;
        }
    }
}

int modulo_judge(char ch[])         //判断字符串ch是否全为0，若全为0，返回1，否则返回0
{
    int i, len;
    len = strlen(ch);
    for (i = 0; i < len; i++) {
        if (ch[i] != '0') {
            return 0;
        }
    }
    return 1;
}

void modulo_Sub(char a1[], char b1[])    //a1为被减数，b1为减数
{
    int lena, lenb, i, len;
    int a[1000] = {0}, b[1000] = {0}, d[1000] = {0};
    lena = strlen(a1);
    lenb = strlen(b1);
    for (i = 0; i < lena; i++) a[i] = a1[lena - 1 - i] - '0';
    for (i = 0; i < lenb; i++) b[i] = b1[lenb - 1 - i] - '0';
    len = lena > lenb ? lena : lenb;
    for (i = 0; i < len; i++)    //相减
    {
        if (a[i] < b[i])    //若被减数不够减，向高位借位
        {
            a[i + 1]--;
            d[i] = a[i] - b[i] + 10;
        } else {
            d[i] = a[i] - b[i];
        }
    }
    //去除高位0
    if (!d[i - 1]) {
        len--;
        //i--;
    }
    //将结果转化为字符逆着赋给数组ans
    for (i = 0; i < len; i++) {
        modulo_ans[i] = d[len - i - 1] + '0';
    }
    //if(modulo_judge(modulo_ans))//若差全为0，则只输出一个
    //  strcpy(modulo_ans,"0");
}

char *modulo_divise(char ina[], char inb[]) {
    strcpy(modulo_dividend, ina);
    strcpy(modulo_divisor, inb);
    char *p;
    char tmp[1000], t[1000];    //tmp储存被除数片段
    int lens, lent, i, j, k, flag = 0;
    memset(modulo_arr, 0, sizeof(modulo_arr));
    if (modulo_judge(modulo_divisor)) {
        p = "除数不能为0!";
        return p;
    }

    if (modulo_Compare(modulo_dividend, modulo_divisor) < 0)   //若被除数小于除数，则商为0，余数为被除数
    {
        strcpy(modulo_arr, modulo_dividend);
        strcpy(modulo_ans, "0");
    } else if (!modulo_Compare(modulo_dividend, modulo_divisor)) //若两数相等，则商为1，余数为0
        modulo_ans[0] = '1';
    else         //若被除数大于除数
    {
        j = lent = 0;
        lens = strlen(modulo_dividend);
        memset(tmp, 0, sizeof(tmp));
        memset(t, 0, sizeof(t));
        for (i = 0; i < lens; i++)   //得到被除数切片,得到整型数组形式的商
        {                      //t的一个元素表示一次相除的商
            //printf("i = %d,j = %d\n",i,j);
            tmp[j++] = modulo_dividend[i];
            flag = 0;
            //printf("tmp = %s\n",tmp);
            while (modulo_Compare(tmp, modulo_divisor) >= 0)    //可以除
            {//用减法获得对应位置的商
                modulo_Sub(tmp, modulo_divisor);
                strcpy(tmp, modulo_ans);
                //printf("new tmp = %s\n",tmp);
                memset(modulo_ans, 0, sizeof(modulo_ans));
                t[lent]++;
                //printf("%d:lent = %d,%s\n",i,lent,t);
                flag = 1;            //对应位置有值
            }
            if (flag)               //将商转换为字符
                t[lent] += '0';
            else                  //对应处无值，即商为0
                t[lent] = '0';
            //printf("t[%d] = %c\n",lent,t[lent] );
            if (tmp[0] == '0') strcpy(tmp, tmp + 1);    //消去首位0
            if (!strcmp(tmp, "0"))     //若tmp为'0'
                j = 0;
            else             //继续在b的后面加值
                j = strlen(tmp);
            lent++;
        }
        k = 0;
        for (i = 0; i < lent; i++) {
            if (t[i] != '0')
                break;           //找到t数组中第一个不为0的位置
        }
        for (j = i; j < lent; j++) {
            modulo_ans[k++] = t[j];
        }
        strcpy(modulo_arr, tmp);
    }
    //if(modulo_judge(modulo_ans))
    //  strcpy(modulo_ans,"0");
    if (modulo_judge(modulo_arr))
        strcpy(modulo_arr, "0");
    p = modulo_ans;
    return p;
}

char *modulo_modulo(char a[], char b[]) {
    modulo_divise(a, b);
    char *p;
    p = modulo_arr;
    return p;
}

void modulo_reset() {
    memset(modulo_dividend, 0, sizeof(modulo_dividend));
    memset(modulo_divisor, 0, sizeof(modulo_divisor));
    memset(modulo_arr, 0, sizeof(modulo_arr));
    memset(modulo_ans, 0, sizeof(modulo_ans));
    modulo_declen = 0;
}



/*
 * 接下来开始利用构造好的除法模板进行两种求余类型的实现
 */


//无符号整数
UnsignedBigNum ModUnsignedBigNum(UnsignedBigNum a, UnsignedBigNum b) {
    UnsignedBigNum c;
    if (a.flag == 0) {
        c.flag = 0;
        strcpy(c.numBody, "0");
        c.length = 0;
        return c;
    }
    strcpy(c.numBody, modulo_modulo(a.numBody, b.numBody));
    c.length = strlen(c.numBody);
    if (modulo_Compare(c.numBody, "0") == 0) {
        c.flag = 0;
    } else {
        c.flag = 1;
    }
    modulo_reset();
    return c;
}


//有符号整数
SignedBigNum ModSignedBigNum(SignedBigNum a, SignedBigNum b) {
    SignedBigNum c;
    c.flag = a.flag * b.flag;
    if (a.flag == 0) {
        c.flag = 0;
        strcpy(c.numBody, "0");
        c.length = 0;
        return c;
    }
    strcpy(c.numBody, modulo_modulo(a.numBody, b.numBody));
    c.length = strlen(c.numBody);
    if (modulo_Compare(c.numBody, "0") == 0) {
        c.flag = 0;
    } else {
        c.flag = a.flag * b.flag;
    }
    modulo_reset();
    return c;
}
