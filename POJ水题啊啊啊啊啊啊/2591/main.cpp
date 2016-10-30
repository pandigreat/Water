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
* 看看提示就明白题目的意思了，思想打表，模仿ugly number那道题
*还是我太菜了
*/
using namespace std;
int mes[10000002] = {1};
//int* mes = (int*)malloc(sizeof(int)*10000000);
int n;
//const int Inf = 0x7FFFFFFF;
int main()
{
    int idx2 = 0, idx3 = 0;
    for(int i = 1; i < 10000000; i++){
        int t2 = mes[idx2] * 2 + 1;
        int t3 = mes[idx3] * 3 + 1;
        int d = min(t2, t3);
        if(d == t2) idx2 ++;
        if(d == t3) idx3 ++;
        mes[i] = d;
    }
    while(scanf("%d", &n) == 1){
        printf("%d\n", mes[n - 1]);
    }

    return 0;

}
