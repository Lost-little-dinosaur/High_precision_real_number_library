#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>
#include<Windows.h>
#include "GUI\gui.h"
#include <stdlib.h>

#include "newCompute\compare.h"
#include "newCompute\division.h"
#include "newCompute\module.h"
#include "newCompute\multiplication.h"
#include "newCompute\plus.h"
#include "newCompute\subtraction.h"

int test() {
    system("chcp 65001");
    int choise;
    start:
    system("cls");

    printf("\n欢迎来到大数计算程序！\n\n");

    printf("1：加法\n\n");
    printf("2：减法\n\n");
    printf("3：乘法\n\n");
    printf("4：除法\n\n");
    printf("5：比较\n\n");
    printf("6：求幂\n\n");
    printf("7：求阶乘\n\n");
    printf("8：求余\n\n");
    printf("9：验证哥德巴赫猜想\n\n");
    printf("0：退出程序\n\n");

    printf("\n请输入您的选择(1/2/3/4/5/6/7/8/9/0)：\n");
    scanf("%d", &choise);

    if (choise == 1) {
        return 1;
    } else if (choise == 2) {
        return 2;
    } else if (choise == 3) {
        return 3;
    } else if (choise == 4) {
        return 4;
    } else if (choise == 5) {
        return 5;
    } else if (choise == 6) {
        return 6;
    } else if (choise == 7) {
        return 7;
    } else if (choise == 8) {
        return 8;
    } else if (choise == 9) {
        return 9;
    } else if (choise == 0) {
        return 0;
    } else {
        printf("输入错误，请重新输入...");
        Sleep(3);
        goto start;
    }
}


int main() {
    system("chcp 65001");
    int end = 0;
    while (end != 1) {
        int flag = test();

        switch (flag) {
            case 1:
                ScanfCheck(1);
                break;
            case 2:
                ScanfCheck(2);
                break;
            case 3:
                ScanfCheck(3);
                break;
            case 4:
                ScanfCheck(4);
                break;
            case 5:
                ScanfCheck(5);
                break;
            case 6:
                ScanfCheck(6);
                break;
            case 7:
                jc();
                break;
            case 8:
                ScanfCheck(8);
                break;
            case 9:
                gdbh();
                break;
            case 0:
                printf("\n感谢使用，再见！\n");
                sleep(1);
                exit(0);
        }
    }
//    if (test() == 1) {
//        ScanfCheck(1);
//    }
//    if (test() == 2) {
//        ScanfCheck(2);
//    }
//    if (test() == 3) {
//        ScanfCheck(3);
//    }
    return 0;
}



//    //防止控制台输出乱码
//    system("chcp 65001");
//    start:
//    srand((unsigned int) time(0));
//    int end = 1, result;
//    while (end) {
//        result = Menu();
//        if (result != 0) {
//            sleep(2);
//            ScanfCheck(result);
//            break;
//        } else {
//
//            printf("输入错误，请重新输入...");
//            Sleep(300);
//            goto start;
//