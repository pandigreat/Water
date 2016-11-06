#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <deque>
#define PII pair<int, int>
#define P pari<int, PII>
#define INF 0x11

using namespace std;
int mes[110][110];
int mes2[110][110], pre[110];
deque<int> step[110][110];
int n, a, b;
int getf(int i){
    return i == pre[i]? i: getf(pre[i]);
}
bool union_set(int i, int j){
    int idx = min(i, j), jdx = max(i, j);
    if(pre[idx] == pre[jdx])
        return true;
    pre[jdx] = idx;
    return false;
}
int solve2(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <=n; i++)
            for(int j = 1; j <= n; j++){
                if(mes2[i][j] > mes2[i][k] + mes2[k][j]){
                    step[i][j] = step[i][k];
                    step[i][j].push_back(k);
                }
            }
    return mes2[a][b];
}
int getr(){
    int ai = a, bi = b, k, r = 0;
    for(int i = 0; i < step[a][b].size(); i++){
        int tm = step[a][b].front();
        if(mes[ai][tm] == 1)
            r++;
        ai = tm;
        step[a][b].pop_front();
    }
    if(mes[ai][bi] == 1)
        r++;
    return r;
}
int main()
{
    while(~scanf("%d %d %d", &n, &a, &b)){
        memset(mes2, 0x11, sizeof(mes2));
        for(int i = 0; i < 110; i++){
            pre[i] = i;
            for(int j = 0; j < 110; j++)
                mes2[i][j] = 2;
            mes2[i][i] = mes[i][i] = 0;
        }
        int k = 0, tmp = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &k);
            for(int j = 1; j <= k; j++){
                scanf("%d", &tmp);
                mes[i][tmp] = 1;
                mes2[i][tmp] = mes2[tmp][i] = 1;
                union_set(i, tmp);
            }
        }
        if(getf(a) != getf(b)){
            printf("-1\n");
            continue;
        }
        int r2 = solve2();
        int r1 = getr();
        printf("%d\n", r2 - r1);
    }
    return 0;
}
