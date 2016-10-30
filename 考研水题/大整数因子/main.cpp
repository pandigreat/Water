#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#include <set>
#define inf 2000000000
#define ll unsigned long long


using namespace std;

set<int> s;
int a, b, l;
char mes[200];
int ans[200];

void solve(){
    bool v = false, f = true;
    for(int k = 2; k < 10; k++){
        int y = 0;
        for(int i = 0; i < l; i++){
            y = y * 10 + ans[i];
            y = y % k;
        }
        if(!y){
            v = true;
            if(f){
                printf("%d", k);
                f = false;
            }else{
                printf(" %d", k);
            }
        }
    }
    if(v) printf("\n");
    else printf("none\n");

}

int main(){
    while(~scanf("%s", mes) && strcmp(mes, "-1")){
        l = strlen(mes);
        for(int i = 0; i < l; i++)
            ans[i] = mes[i] - '0';
        solve();
    }
    return 0;
}