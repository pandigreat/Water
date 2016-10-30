#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
/*
*permutation ²»ÄÜA
*/
using namespace std;
set<char> s;
set<char> shit;
int n;
char mes[10010];
int f[290];
int cnt;
int main()
{
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        scanf("%s", mes);
        int l = strlen(mes);
        cnt = 0;
        int res = 0;
        memset(f, 0, sizeof(f));
        for(int i = 0; i < l; i++){
            if(cnt < n && f[mes[i]] == 0){
                f[mes[i]] ++;
                cnt ++;
            }else if(cnt < n && f[mes[i]] > 0){
                f[mes[i]] --;
                cnt --;
            }else if(cnt < n && f[mes[i]] < 0){
                f[mes[i]] ++;
            }else if(cnt == n && f[mes[i]] == 0){
                res ++;
                f[mes[i]] --;
            }else if(cnt == n && f[mes[i]] < 0){
                f[mes[i]] ++;
            }else{
                cnt --;
                f[mes[i]] --;
            }
        }
        if(res){
            printf("%d customer(s) walked away.\n", res);
        }else
            printf("All customers tanned successfully.\n");
    }

    return 0;
}
