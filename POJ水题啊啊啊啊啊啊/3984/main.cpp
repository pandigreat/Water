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
* dfs + 回溯而已
* 还是我太菜了
*/
using namespace std;
int mes[10][10];
bool v[5][5];
bool res[5][5];
int cnt = 0xff;
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int x, y;

void cpy(){
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            res[i][j] = v[i][j];
}

void dfs(int i, int j, int d){
    d++;
    if(i == 4 && j == 4 && cnt > d) {
        cnt = d;
        cpy();
    }
    for(int k = 0; k < 4; k++){
        int dx = i + dir[k][0];
        int dy = j + dir[k][1];
        if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5 && !mes[dx][dy] && !v[dx][dy]){
            v[dx][dy] = true;
            dfs(dx, dy, d + 1);
            v[dx][dy] = false;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &mes[i][j]);
    memset(v, 0, sizeof(v));
    memset(res, 0, sizeof(res));
    v[0][0] = true;
    dfs(0, 0, 0);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(res[i][j])
                printf("(%d, %d)\n", i, j);

    return 0;
}





