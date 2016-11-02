#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;
int mes[10011][10011], dist[10011];
bool f[10011];
const int max_int = 999999;
int n, m, res;
void solve(){
    res = 0;
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++)
        dist[i] = mes[1][i];
    int v = 1;
    int u;
    for(int i = 1; i <= n; i++){
        f[v] = true;
        int min_int = max_int;
        for(int j = 1; j <= n; j++){
            if(!f[j] && dist[j] < min_int)
                u = j, min_int = dist[j];
        }
        res += min_int;
        for(int j = 1; j <=n; j++){
            if(!f[j] && mes[u][j] < dist[j])
                dist[j] = mes[u][j];
        }
        v = u;
    }
}

int main()
{
    int a, b, c, cnt;
    while(scanf("%d", &n) != EOF){
        m = (n) * (n - 1) / 2;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; ++j)
                mes[i][j] = max_int;
        }
        while(m--){
            scanf("%d %d %d", &a, &b, &c);
            mes[a][b] = c;
        }

    }

    return 0;
}
