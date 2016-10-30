#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;
int n, t;
/***
*PE 为啥呢？因为在结果printf中，数字和字母中间有两个空格。。。。。。。
*醉
*/
char mes [3][19] = {"DEFICIENT", "PERFECT", "ABUNDANT"};
int f(int i){
    int h = i / 2;
    int t = 1, res = 0;
    while(t <= h){
        if(i % t == 0)
            res += t;
        t++;
    }
    return res;
}
int cnt(){
    if(t == n) return 0;
    else if(t < n) return -1;
    return 1;
}
int dd = 0;
int main()
{

    while(scanf("%d", &n) != EOF && n){
        if(!dd)
            printf("PERFECTION OUTPUT\n");
        dd++;
        t = f(n);
        printf("%5d  %s\n", n, mes[cnt() + 1]);
    }


    printf("END OF OUTPUT\n");
    return 0;
}
