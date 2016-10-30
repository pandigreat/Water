#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
int n, t;
int pre[10010];
int a, b;
int main(){

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i <= n; i ++)
            pre[i] = i;
        for(int i = 1; i < n; i++){
            scanf("%d %d", &a, &b);
            pre[b] = a;
        }
        scanf("%d %d", &a, &b);
        int i = a, j = b;
        vector<int>  v1, v2;
        v1.push_back(i); v2.push_back(j);
        while(i != pre[i]){
            v1.push_back(pre[i]);
            i = pre[i];
        }
        while(j != pre[j]){
            v2.push_back(pre[j]);
            j = pre[j];
        }
        i = v1.size() - 1; j = v2.size() - 1;
        while(i >= 0 && j >= 0){
            if(v1[i] != v2[j]) break;
            i--; j--;
        }
        printf("%d\n", v1[++i]);
    }


	return 0;
}
