#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;
int mes[10010][10010];
bool v[10010];
int n;
queue <int> q;
void bfs(){
    q.push(0);
    int p = q.front();
    v[p] = true;
    printf("%d\n", p);
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(mes[p][i] && !v[i]){
                v[i] = true;
                printf("%d\n", i);
                q.push(i);
            }
        }
    }
}
int main()
{
    memset(v, 0, sizeof(10010));
    memset(mes, 0, sizeof(10010));
    FILE* fp = fopen("1.txt", "r");
    fscanf(fp, "%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            fscanf(fp, "%d", &mes[i][j]);
    bfs();
    fclose(fp);

    return 0;
}

