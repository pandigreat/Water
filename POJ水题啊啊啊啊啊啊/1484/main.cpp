#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;
int n, m, c, j;
bool v[101];
int mes[110];
/***
*知道为啥一直过不了不？
*因为你的答案输出中是Sequence #%d 而不是 Sequence %d，才会WA
*醉
*/

int main()
{
    while(scanf("%d %d %d", &n, &m, &c) != EOF){
       if(!n && !m && !c) break;
       int res = 0; bool f = true;
       memset(v, 0, sizeof(v));
       memset(mes, 0, sizeof(mes));
       for(int i = 1; i <= n; i++){
          scanf("%d", &mes[i]);
       }
       int pre = 0, tmp = 0;
       for(int i = 0; i < m; i++){
          scanf("%d", &tmp);
          if(f && !v[tmp]){
             v[tmp] = true;
             pre += mes[tmp];
             if(pre > c) f = 0;
             if(pre > res) res = pre;
          }else if (f && v[tmp]){
             v[tmp] = false;
             pre -= mes[tmp];
          }
          //if(pre > c) f = 0;
          //if(f && res < pre) res  = pre;
       }
       printf("Sequence %d\n", ++j);
       if(!f){
        printf("Fuse was blown.\n\n");
       }else{
        printf("Fuse was not blown.\n");
        printf("Maximal power consumption was %d amperes.\n\n", res);
       }

    }
    return 0;
}
