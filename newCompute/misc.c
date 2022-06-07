//
// Created by Dinosaur on 2022/6/5.
//

#include "misc.h"
#include "compare.h"
#include "module.h"
#include "plus.h"
#include "division.h"
#include "multiplication.h"
#include <string.h>

void findPrimeNumbers(UnsignedBigNum a, UnsignedBigNum PrimeArr[MAXSIZE / 20]) {//MAXSIZE/20差不多是最多的质因数
    UnsignedBigNum b;
    long long i = 0;
    int flag;
    UnsignedBigNum tempOne;
    UnsignedBigNum tempNum;
    UnsignedBigNum tempA;

    tempOne.length = 1;
    tempOne.numBody[0] = '1';
    tempOne.numBody[1] = '\0';
    tempNum.flag = 1;
    tempNum.length = 1;
    tempNum.numBody[0] = '1';
    tempNum.numBody[1] = '\0';
    tempNum.flag = 1;

    b.length = 1;
    b.numBody[0] = '2';
    b.flag = 1;
    tempA = a;
//    tempA = DiviseUnsignedBigNum(a, b);//自动向下取整
//    tempA = plusUnsignedBigNum(tempA, tempOne);
    while (compareUnsignedBigNum(tempA, b) > 0) {
        flag = 0;
        tempNum.length = 1;
        tempNum.numBody[0] = '1';
        tempNum.numBody[1] = '\0';
        tempNum.flag = 1;
        while (compareUnsignedBigNum(b, tempNum) > 0) {
            if (ModUnsignedBigNum(b, tempNum).flag == 0 && (tempNum.numBody[0] != '1' || tempNum.length > 1)) {
                flag = 1;
                break;
            }
            tempNum = plusUnsignedBigNum(tempNum, tempOne);
        }
        if (flag == 0) {
            PrimeArr[i] = b;
            ++i;
        }
        b = plusUnsignedBigNum(b, tempOne);
    }

}

void findFactorNumbers(UnsignedBigNum a, UnsignedBigNum fillInArr[MAXSIZE / 20],
                       UnsignedBigNum PrimeArr[MAXSIZE / 20], int primeNum) {//MAXSIZE/20差不多是最多的质因数
    UnsignedBigNum b;
    long long i = 0;
    int flag = 0;
    UnsignedBigNum tempOne;
    UnsignedBigNum tempA;

    tempOne.length = 1;
    tempOne.numBody[0] = '1';
    tempOne.numBody[1] = '\0';
    tempOne.flag = 1;
    b.length = 1;
    b.numBody[0] = '2';
    b.flag = 1;
    tempA = DiviseUnsignedBigNum(a, b);//自动向下取整
    tempA = plusUnsignedBigNum(tempA, tempOne);
    while (compareUnsignedBigNum(tempA, b) > 0) {
        for (int j = 0; j < primeNum; ++j) {
            if (strcmp(PrimeArr[j].numBody, b.numBody) == 0) {
                if (ModUnsignedBigNum(a, b).flag == 0) {
                    fillInArr[i] = b;
                    ++i;
                }
            } else {
                continue;
            }
        }
        b = plusUnsignedBigNum(b, tempOne);
    }

}

void DecomposedPrimeFactor(UnsignedBigNum num, UnsignedBigNum fillInArr[MAXSIZE / 20], int factorNum) {
    UnsignedBigNum a, b, res;
    for (int i = 0; i < factorNum / 2; ++i) {
        a = fillInArr[i];
        for (int j = 0; j < factorNum; ++j) {
            b = fillInArr[j];
            res = multiplyUnsignedBigNum(a, b);
            if (strcmp(num.numBody, res.numBody) == 0) {
                printf("找到一个解：%s * %s = %s\n", a.numBody, b.numBody, res.numBody);
            }
        }
    }
}

void solveGoldbachConjecture(UnsignedBigNum num, UnsignedBigNum primeArr[MAXSIZE / 20], int primeNum) {
    UnsignedBigNum a, b, res;
    for (int i = 0; i < primeNum / 2; ++i) {
        a = primeArr[i];
        for (int j = 0; j < primeNum; ++j) {
            b = primeArr[j];
            res = plusUnsignedBigNum(a, b);
            if (strcmp(num.numBody, res.numBody) == 0) {
                printf("找到一个解：%s + %s = %s\n", a.numBody, b.numBody, res.numBody);
            }
        }
    }
}


void solveGoldbachConjectureAll(UnsignedBigNum num) {
    UnsignedBigNum b;
    UnsignedBigNum resArr[MAXSIZE / 20];
    UnsignedBigNum primeArr[MAXSIZE / 20];

    b.length = 1;
    b.numBody[0] = '2';
    b.numBody[1] = '\0';
    b.flag = 1;
    findPrimeNumbers(num, primeArr);
//    findPrimeNumbers(num, resArr);
    long primeNum = 0;
    long factorNum = 0;
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(primeArr[i].numBody, "") != 0) {
//            printf("%s\n", primeArr[i].numBody);
            ++primeNum;
        } else {
            break;
        }
    }
    printf("在小于等于%s的范围内一共找到%d个质数！\n", DiviseUnsignedBigNum(num, b).numBody, primeNum);

    solveGoldbachConjecture(num, primeArr, primeNum);
}

void DecomposedPrimeFactorAll(UnsignedBigNum a) {
    UnsignedBigNum b;
    UnsignedBigNum resArr[MAXSIZE / 20];
    UnsignedBigNum primeArr[MAXSIZE / 20];

    b.length = 1;
    b.numBody[0] = '2';
    b.numBody[1] = '\0';
    b.flag = 1;

    findPrimeNumbers(a, primeArr);
//    findPrimeNumbers(a, resArr);
    long primeNum = 0;
    long factorNum = 0;
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(primeArr[i].numBody, "") != 0) {
//            printf("%s\n", primeArr[i].numBody);
            ++primeNum;
        } else {
            break;
        }
    }
    printf("在小于等于%s的范围内一共找到%d个质数！\n", DiviseUnsignedBigNum(a, b).numBody, primeNum);

    findFactorNumbers(a, resArr, primeArr, primeNum);
    for (int i = 0; i < MAXSIZE / 20; ++i) {
        if (strcmp(resArr[i].numBody, "") != 0) {
            printf("%s\n", resArr[i].numBody);
            ++factorNum;
        } else {
            break;
        }
    }
    printf("在%d个质数里一共找到%d个质因数！\n", primeNum, factorNum);

}

//141713509714041768291009034007469332501261937095702722003983333035242694123348539249486387748961504383786315063881390962154801871549410885800454218182231903004199381151502564553300177136248895473023386249911160776402429108476678420204910989308432349419276518597739718592702167371279017773270523371984593706229023268072101705655873050577098802074001043213121883536951850803610718628144454102084624556777765783046188427130779201836084192738989678194936692420254307134672551522160122712990950676292240485363112742297663536084857839933941190057205923404281948666190852336035690979209874817281769835452609160777459245831473345532734007879447125378089292807113476414301992172091510477295839460949898804824494928887665718357317229115343904701747559771959653800087820016837462893994040559224502766008042301119336422719674886882819213329497186092336276255067649937853746667853044398941170982435345828060743331520247731317047540143797197967475469589815717319254493453774230208940348321411951772782359743130710979035283119405102485771483073908309461788375469314829110718120433555624606975851000997776452726007214376423252436205250159574405796631600628246006180341853053968170171010536876414130589947333845072928867755948830839943680239327722089275489586853974775127962936997544668986083597884983061963675783044959706129419869791904432514645444368135881274378646646270246424234432770783431720929002040065824985504150390625
//50334398756815134729670713763059015310394343248291084925812716303091591650354885321974947592950560617817003370563753727698637625219223498551938714687078943131869383659045572651365605395070693869868683989496472046597535698728503839203023842634951989910598699666771920431376626211009549515306100323801174963884555461556041961676908154596478927643606641853408450422457588132714420999163343163009318759862572557870601849673983949315218639261613502852297348794494132109571428667222772042739009189594524240981015589985671038559081154405201179920235264738180359469428482730500904756241274676441315188661893263668854668595194435537032705142771799652785359574604136159512444181355672447630233267823759090327902926626319097749841718905820024652986185397148972706336695400242486426261199058623855486213867261080861815845907134813209031166073262448172602360708693392665817969943141946468967185172092448263024285317394751112886888476044862016905386363841365021305795881671367977541091388555312771280406910570657024800848236868794133234696326676769375435811183728743872875033327077970349753660074502444961657735817044978697971176075975700750224241377766131917929490969552957111447673258498102830301159767374767488570742597420363551641432099407299791763063259898448709445123350440622101449489786407709684843817668762909140976623359689033471195860891696169951890349780553754747373956533809584675070432560363706879451514566132472615713342612281


/*
    system("chcp 65001");
    struct FloatBigNum a;
    struct FloatBigNum b;
    struct FloatBigNum r;

    a.flag = 1;
    b.flag = 1;
    char *s1 = "224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341";
    char *s2 = "224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341";

    char *s3 = "224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341";
    char *s4 = "224353290051238461283641826354192873469128734691827356918736918723649812736498237619872461827591374812364981723649812364987123648712364971823649817345987346159832649812364981273469817236491273649817365987126394861293451982364978123649871263948712697856193287561982734691273846918273649871236498712364987126349871263498712639847612973846918465981236491728341";
//    2361576464370916
//    2361576464370916
    strcpy(a.integer, s1);
    strcpy(a.decimal, s2);
    strcpy(b.integer, s3);
    strcpy(b.decimal, s4);
    a.lengthInteger = strlen(s1);
    a.lengthDecimal = strlen(s2);
    b.lengthInteger = strlen(s3);
    b.lengthDecimal = strlen(s4);

    r=multiplyFloatBigNum(a, b);
    if (r.flag == -1) {
        printf("-");
    }
    printf("结果如下：%s.%s", r.integer,r.decimal);
    return 0;
 */

/*
SignedBigNum a;

    a.flag = -1;
    char *str1 = "000645689706543889";
    a.length = strlen(str1);
    strcpy(a.numBody, str1);
    printf("%d ",exponentiationSignedBigNum(a, 4).flag);
    printf("%s", exponentiationSignedBigNum(a, 4).numBody);
 */

/*
UnsignedBigNum a;

    a.flag = 1;
    char *str1 = "123456543212345";
    a.length = strlen(str1);
    strcpy(a.numBody, str1);
    printf("%s", exponentiationUnsignedBigNum(a, 100).numBody);
 */

/*
FloatBigNum a;
    FloatBigNum r;

    a.flag = -1;
    char *str1 = "123";
    char *str2 = "45";
    a.lengthInteger = strlen(str1);
    a.lengthDecimal = strlen(str2);
    strcpy(a.integer, str1);
    strcpy(a.decimal, str2);
    r = exponentiationFloatBigNum(a, 3);
    printf("%d ", r.flag);
    printf("%s.%s", r.integer, r.decimal);
 */


/*
 FloatBigNum a;
    FloatBigNum r;

    a.flag = -1;
    char *str1 = "123";
    char *str2 = "45";
    a.lengthInteger = strlen(str1);
    a.lengthDecimal = strlen(str2);
    strcpy(a.integer, str1);
    strcpy(a.decimal, str2);
    r = exponentiationFloatBigNum(a, 3);
    printf("%d ", r.flag);
    printf("%s.%s", r.integer, r.decimal);

 */



/*
system("chcp 65001");
    UnsignedBigNum a, b;
    UnsignedBigNum resArr[MAXSIZE / 20];
    UnsignedBigNum primeArr[MAXSIZE / 20];

    b.length = 1;
    b.numBody[0] = '2';
    b.numBody[1] = '\0';
    b.flag = 1;
    a.flag = 1;
    char *str1 = "500";
    a.length = strlen(str1);
    strcpy(a.numBody, str1);

    DecomposedPrimeFactorAll(a);
    solveGoldbachConjectureAll(a);
 */
