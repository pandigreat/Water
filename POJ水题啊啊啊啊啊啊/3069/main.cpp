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
#define max(x, y) (x)>(y)?(x):(y)

using namespace std;
int r, n;
int mes[10010];

bool c(int s, int t){
    if(t != s && mes[t] - mes[s] <= 2 * r && mes[t] - mes[t - 1] <= r){
        bool f = false;
        for(int i = s; i <= t && !f; i++){
            if(mes[i] - mes[s] <= r && mes[t] - mes[i] <= r)
                f = true;
        }
        return f;
    }
    else
        return false;
}

int main()
{
    while(scanf("%d %d", &r, &n) == 2 && r != -1 && n != -1){
        if(n == 0){
            printf("0\n");
            continue;
        }
        int res = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", mes + i);
        sort(mes, mes + n);
        int s = 0, t = s;
        while(t < n){
            if(t == s)
                t ++;
            else if(c(s, t))
                t++;
            else{
                res ++;
                s = t;
            }
        }
        printf("%d\n", res + 1);
    }
    return 0;
}




