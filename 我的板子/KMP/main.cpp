#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
/**
* 之后考虑的是如果两个字符一样应该做的一个处理
*还是我太菜了
*/
using namespace std;

int n;
int next[10010];

void GetNext(const char t[]){
    next[0] = 0;
    int l = strlen(t), i = 1, j = 1;
    while(i < l){
        if(j == 0 || t[i] == t[j] next[++i] = ++j;
        else j = next[j];
    }

}

int kmp_cpy(const char str[], const char t[]){
    int l1 = strlen(str), l2 = strlen(t);
    int i = 0, j = 0;
    while(i < l1 && j < l2){
        if(str[i] == t[j]) i++, j++;
        else j = next[j];
    }
    if(j >= l2) return i - j - 1;
    return -1;
}

int main()
{
    char str[30030];
    char t[10010];
    scanf("%s", str);
    scanf("%s", t);

    printf("%d\n", cmp(str, t));

    return 0;
}




