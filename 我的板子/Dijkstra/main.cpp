#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;
const int inf = 200000;
const int maxsum = 20010;
int mes[maxsum][maxsum];
int dist[maxsum];
int pre[maxsum];
int v[maxsum];
int n, m, s;

void Dijikstra(){
   //  for(int i = 0; i < n; i++)
   //     mes[i][i] = 0;
    for(int i = 0; i < n; i++){
        dist[i] = mes[s][i];
        if(dist[i] < inf) pre[i] = s;
        else pre[i] = 0;
    }
    v[s] = true;
    dist[s] = 0;
    for(int i = 1; i < n; i++){
        int tmp = inf;
        int u = s;
        for(int j = 0; j < n; ++j){
            if(!v[j] && tmp > dist[j])
                tmp = dist[j], u = j;
        }
        v[u] = true;
        for(int j = 0; j < n; j++){
            if(!v[j] && mes[u][j] < inf){
				tmp = mes[u][j] + dist[u];
				if(dist[j] > tmp) dist[j] = tmp, pre[j] = u;
			}
        }
        s = u;
    }
}

int main()
{

    memset(pre, 0, sizeof(pre));
    FILE* fp;
    fp = fopen("1.txt", "r");
    fscanf(fp, "%d %d", &n, &s);
    int pt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(fp, "%d", &pt);
            if(!pt)
                mes[i][j] = inf;
            else mes[i][j] = pt;
        }
    }
    Dijikstra();
    for(int i = 0; i < n; i++)
    printf("%d ", dist[i]);
    fclose(fp);
    return 0;
}

/**
    FILE* fp;
    fp = fopen("1.txt", "r");
    fscanf(fp, "%d", &l);
    for(int i = 0; i < l; i++)
        fscanf(fp, "%d", &arr[i]);
    qSort(0, l - 1);
    while(--l >= 0)
        printf("%d ",arr[l]);
    fclose(fp);
    return 0;
*/
/**
int bcd(int a, int b){
	return (a % b == 0)? b: bcd(b, a % b);
}
*/