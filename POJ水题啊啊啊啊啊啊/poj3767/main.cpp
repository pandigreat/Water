#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define PII pair<int, int>
#define inf 0x7f7f7f7f

using namespace std;
int n, m, k;
int mes[603][603];
int country[603];
bool vis[603];
int dist[603];
int pre[603];
int has, res;
void solve(int s,int d, int pos){
    memset(dist, 0x7f, sizeof(dist));
    for(int i = 1; i <= n; i++){
        if(mes[1][i] < inf)
            dist[i] = mes[1][i];
        else pre[i] = 0;
    }
    dist[1] = 0;
    vis[1] = true;
    for(int i = 1; i < n; i++){
        int tmp = inf;
        int u = s;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && tmp > dist[j]){
                tmp = dist[j];
                u = j;
            }
        }
            vis[u] = true;
            for(int j = 1; j <= n; j++){
                if(!vis[j] && mes[u][j] < inf){
                    if(pos == 2 && country[j] == 1)
                        continue;
                    tmp = mes[u][j] + dist[u];
                    if(dist[j] > tmp)
                        dist[j] = tmp, pre[j] = u;
                }
            }
            s = u;

    if(dist[2] < inf) printf("%d\n", dist[2]);
    else printf("-1\n");
}
int main()
{
    while(~scanf("%d", &n) && n){
        memset(vis, 0, sizeof(vis));
        memset(mes, 0x7f, sizeof(mes));
        has = 1;
        res = 0x7f7f7f7f;
        scanf("%d", &m);
        int a, b, t;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &a, &b, &t);
            mes[a][b] = t;
            mes[b][a]= t;
        }
        for(int i = 1; i <= n; i++) scanf("%d", country + i);
        for(int i = 1; i <= n; i++){ ///¼ôÖ¦
            for(int j = 1; j <= n; j++){
                if(country[i] != country[j]){
                    if(country[i] == 1)
                        mes[j][i] = inf;
                    else
                        mes[i][j] = inf;
                }
            }
        }
        solve(1, 0, 1);
    }
    return 0;
}
