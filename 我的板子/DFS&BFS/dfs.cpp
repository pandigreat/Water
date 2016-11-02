


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
void dfs(int i){
    v[i] = true;
    for(int j = 0; j < n; j++){
        if(mes[i][j] && !v[j]){
            printf("%d\n", j);
            dfs(j);
        }
    }
}
void DFS(){
    v[0] = true;
    printf("%d\n", 0);
    for(int i = 0; i < n; i++){
        if(mes[0][i] && !v[i]){
            printf("%d\n", i);
            dfs(i);
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
    DFS();
    fclose(fp);

    return 0;
}
