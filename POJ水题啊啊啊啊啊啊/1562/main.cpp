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
* ������ʾ��������Ŀ����˼�ˣ�˼����ģ��ugly number�ǵ���
*������̫����
*/
using namespace std;
char mes[1001][1001];
int m, n;
bool v[1001][1001];
int cnt;
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
void dfs(int a, int b){
    v[a][b] = true;
    for(int i = 0; i < 8; i++){
        int dx = a + dir[i][0];
        int dy = b + dir[i][1];
        if(dx >= 0 && dx < m && dy >= 0 && dy < n && mes[dx][dy] == '@' && !v[dx][dy])
            dfs(dx, dy);
    }
}
int main()
{
    while(scanf("%d %d", &m, &n) == 2 && m && n){
        for(int i = 0; i < m; i++)
            scanf("%s", mes[i]);

        cnt = 0;
        memset(v, 0, sizeof(v));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mes[i][j] != '*' && !v[i][j]){
                    cnt ++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
