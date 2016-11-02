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

int dp[10010][10010];
char str1[10010], str2[10010];

int main()
{
    scanf("%s %s", str1, str2);
    int l1 = strlen(str1), l2 = strlen(str2);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < l2; j++){
            if(str1[i] == str2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    printf("%d\n", dp[l1][l2]);
    return 0;
}




