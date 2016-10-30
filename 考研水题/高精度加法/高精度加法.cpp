#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
using namespace std;
/**
*求2个浮点数相加的和 题目中输入输出中出现浮点数都有如下的形式：
P1P2...Pi.Q1Q2...Qj 对于整数部分，P1P2...Pi是一个非负整数 对于小数部分，Qj不等于0
*/
/**
Input
2
0.111111111111111111111111111111
0.111111111111111111111111111111

10000000.655555555555555555555555555555
1.444444444444444444444444444445
*/
/**
Out
0.222222222222222222222222222222
10000002.1
*/
typedef struct Bint{
    int high[1010];
    int low[1010];
    int ps;
    int p;
    int dels;
    int del;
}Bint;
Bint str1;
Bint str2;
char a[1010], b[1010];
int t;
int main(){

    while(scanf("%d", &t) == 1){
        while(t--){
        scanf("%s %s", a, b);
        Bint res;
        str1.p = str2.p = str1.del = str2.del = 0;
        str1.ps = str1.dels = str2.ps = str2.dels = 0;

        memset(str1.low, 0, sizeof(str1.low));
        memset(str2.low, 0, sizeof(str2.low));
        memset(res.low, 0, sizeof(res.low));
        int l1 = strlen(a), l2 = strlen(b), i = 0, j = 0;
        for(bool v = true; i < l1; i++){
            if(v && a[i] != '.') str1.high[i] = a[i] - '0';
            else if(a[i] == '.'){v = false; str1.p = i; str1.del = l1 - i - 1;}
            else str1.low[i - str1.p - 1] = a[i] - '0';
        }
        for(bool v = true; j < l2; j++){
            if(v && b[j] != '.') str2.high[j] = b[j] - '0';
            else if(b[j] == '.'){v = false; str2.p = j; str2.del = l2 - j - 1;}
            else str2.low[j - str2.p - 1] = b[j] - '0';
        }
        ///前导0消除
        while(str1.ps < str1.p - 1 && str1.high[str1.ps] == 0) str1.ps++;
        while(str2.ps < str2.p - 1 && str2.high[str2.ps] == 0) str2.ps++;

        int carry = 0, tmp;
        int k = res.del = str1.del > str2.del? str1.del - 1: str2.del - 1;
        while(k >= 0){
            tmp = carry + str1.low[k] + str2.low[k];
            carry = tmp / 10;
            res.low[k--] = tmp % 10;
        }
        i = str1.p - 1;
        j = str2.p - 1;
        res.p = k = max(str2.p, str1.p);
        while(i >= str1.ps && j >= str2.ps){
            tmp = carry + str1.high[i--] + str2.high[j--];
            carry = tmp / 10;
            res.high[k--] = tmp % 10;
        }
        while(i >= str1.ps){
            tmp = carry + str1.high[i--];
            carry = tmp / 10;
            res.high[k--] = tmp % 10;
        }
        while(j >= str2.ps){
            tmp = carry + str2.high[j--];
            carry = tmp / 10;
            res.high[k--] = tmp % 10;
        }
        if(carry){
            res.high[k] = carry; res.ps = k;
         }else{
            res.ps = k + 1;
        }
        ///后导0消除
        while(res.del >= 0 && !res.low[res.del]) res.del--;
        ///打印
        for(i = res.ps; i <= res.p; i++) printf("%d", res.high[i]);
        if(res.del >= 0){
            printf(".");
            for(i = 0; i <= res.del; i++) printf("%d", res.low[i]);
        }
        printf("\n");
        }
    }
    return 0;
}

