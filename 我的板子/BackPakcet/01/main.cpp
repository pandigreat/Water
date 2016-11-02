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


int w[10010], v[10010];
int mes[10010][10010];
int vis[10010];
int l = 0;
int  W;
int main()
{

    memset(mes, 0, sizeof(mes));
    memset(vis, 0, sizeof(vis));
    scanf("%d %d", &l, &W);
    for(int i = 1; i <= l; i++)
        scanf("%d %d", w + i, v + i);

    for(int i = 1; i <= l; i++){
        int tw = w[i];
        int tv = v[i];
        for(int j = 0; j <= W; j++){
            if(j < tw)
                mes[i][j] = mes[i - 1][j];
            else


               mes[i][j] = max(mes[i - 1][j], mes[i - 1][j - tw] + tv);
        }
    }

    printf("Answer %d\n", mes[l][W]);
    int i = l, j = W;
    while(i){
        if(mes[i][j] == mes[i -1][j - w[i]] + v[i])
            printf("%d\n", i), j -= w[i];
        i --;
    }
    return 0;
}




