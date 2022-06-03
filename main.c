
#include "GUI\gui.h"
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include<Windows.h>
#include "..\Utils\Utils.h"
int main()
{
    //防止控制台输出乱码
    system("chcp 65001");
    int end=1,result;
    while(end){
        result=Menu();
        switch(result){
            case 1:{
                int* plus=  ScanfCheck();
                printf("%d%d",plus,plus+1);}
                /*if(*plus==1 && *plus+1==1){

                }*/
                break;
            case 2:
                Help();
                break;
            case 3:
                About();
                break;
            case 0:
                end=0;break;
        }
    }

    return 0;
}