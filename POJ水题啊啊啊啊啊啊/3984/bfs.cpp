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
int mes[10][10];
bool v[5][5];
bool res[5][5];
int cnt = 0xff;
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int x, y;
typedef struct ty{
    int x;
    int y;
}ty;
ty pre[5][5];
/*bfs搜索，V进行记忆，防止能够那啥，往回走*/
void bfs(){
    queue<ty> q;
    q.push(ty{0, 0});
    while(!q.empty()){
        ty tmp =  q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int dx = tmp.x + dir[d][0];
            int dy = tmp.y + dir[d][1];

            if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5 && !mes[dx][dy] && !v[dx][dy]){
                v[dx][dy] = true;
                ty tx = ty{dx, dy};
                pre[dx][dy].x = tmp.x;
                pre[dx][dy].y = tmp.y;
                if(dx == 4 && dy == 4)
                    return ;
                q.push(tx);

            }
        }

    }
}
/*模拟栈输出*/
void P(int x, int y){

    if(pre[x][y].x != -1 && pre[x][y].y != -1)
        P(pre[x][y].x, pre[x][y].y);
    printf("(%d, %d)\n", x, y);

}

int main()
{
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            scanf("%d", &mes[i][j]);
    memset(v, 0, sizeof(v));
    v[0][0] = 1;
    bfs();
    P(4, 4);

    return 0;
}





