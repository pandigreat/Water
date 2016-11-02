#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#define PII pair<int, int>
#define P pair<int, PII >
using namespace std;
int n, mes[110][110], pre[110];
int res;

int getPre(int i){
    return i == pre[i]? i: getPre(pre[i]);
}

bool union_set(int i, int j){
    i = getPre(i);
    j = getPre(j);
    if(i == j)
        return false;
    pre[i] = j;
    return true;
}

struct cmp{
    bool operator()(P a, P b){
        return a.first > b.first;
    }
};

int main()
{
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &mes[i][j]);
        res = 0;
        for(int i = 0; i < 110; i++) pre[i] = i;
        priority_queue<P, vector<P>, cmp> q;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                q.push(P(mes[i][j], PII(i, j)));
            }
        }
        while(!q.empty()){
            P p = q.top();
            q.pop();
            if(union_set(p.second.first, p.second.second)){
                res += p.first;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
