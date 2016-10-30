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
char mes[1001][1001];
int m, n;
bool v[1001][1001];
int cnt;
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int x, y;
void dfs(int a, int b){
    v[a][b] = true;
    for(int i = 0; i < 4; i++){
        int dx = a + dir[i][0];
        int dy = b + dir[i][1];
        if(dx >= 0 && dx < n && dy >= 0 && dy < m && mes[dx][dy] == '.' && !v[dx][dy]){
            cnt++;
            dfs(dx, dy);
        }

    }
}

int main()
{
    while(scanf("%d %d", &m, &n) == 2 && m && n){
        for(int i = 0; i < n; i++)
            scanf("%s", mes[i]);
        cnt = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(mes[i][j] == '@')
                    x = i, y = j;
        }
        memset(v, 0, sizeof(v));
        dfs(x, y);
        printf("%d\n", cnt);
    }
    return 0;
}
