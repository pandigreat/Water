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

int dp[10010];
int w[10010], v[10010];
int l, W;

int main()
{
    scanf("%d %d", &l, &W);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < l; i ++)
        scanf("%d %d", w + i, v + i);

    for(int i = 0; i < l; i ++){
        for(int j = w[i]; j < W; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }

    return 0;
}




