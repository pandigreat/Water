#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define inf 2000000000
#define ll unsigned long long

using namespace std;

int m, n;
char a[10010];
char b[10010];
char res[10010];
char* p = res;

int main(){
    while(scanf("%s%s", a, b) == 2){
        int l1 = strlen(a) - 1;
        int l2 = strlen(b) - 1;
        int k = max(l1, l2) + 1;
        memset(res, '\0', sizeof(res));
        int c = 0, tmp;
        while(l1 >= 0 && l2 >= 0){
            tmp = a[l1--] + b[l2--] + c - 2 * '0';
            p[k--] = '0' + tmp % 10;
            c =  tmp / 10;
        }
        while(l1 >= 0){
            tmp = a[l1--] - '0' + c;
            p[k--] = '0' + tmp % 10;
            c = tmp / 10;
        }
        while(l2 >= 0){
            tmp = a[l2--] - '0' + c;
            p[k--] = '0' + tmp % 10;
            c = tmp / 10;
        }
        if(!k) p[k] = '0' + c;
        if(res[0] == '\0') p++;
        printf("%s\n", p);
    }
    return 0;
}
