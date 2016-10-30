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
* 顺便考虑一下奇数偶数罢了
*还是我太菜了
*/
using namespace std;
int n;
char mes[100];
int a, b;
int main()
{
    if(scanf("%d", &n)==1){
        while(n--){
            scanf("%d %d", &a, &b);
            if(a < b || (a - b) & 0x1)
                printf("impossible\n");
            else{
                int d = a - b;
                int res1 = b + d / 2;
                a = a - res1;
                printf("%d %d\n", res1, a);
            }
        }
    }

    return 0;
}
