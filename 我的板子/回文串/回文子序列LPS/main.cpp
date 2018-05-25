#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
///这个是求最长回文子序列的，
///
using namespace std;
int m, n;
char mes[10010];
int dp[10010][10010];
///可以类比lcs,递归的方法有重复计算的地方
int lps(const char* a, int i, int j){
    if(i == j) return 1; ///长度为1
    if(i > j) return 0; ///只是计算[i...j]之间的长度而已啊
    if(a[i] == a[j]) return lps(a, i + 1, j - 1) + 2;
    return max(lps(a, i, j - 1), lps(a, i + 1, j));
}

void solve(){
    int l = strlen(mes);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < l; i++) dp[i][i] = 1;
	for(int i = l - 1; i >= 0; i--){
		dp[i][i] = 1;
		for(int j = i+1; j < l; j++){
			if(mes[i] == mes[j]) 
				dp[i][j] = dp[i+1][j-1] + 2;
			else
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}
    
    printf("%d\n", dp[0][l - 1]);///返回子串mes[0][l - 1] 的结果
}

int main(){

    while(scanf("%s", mes) == 1){
        printf("%d\n", lps(mes, 0, strlen(mes) - 1));
    }
    return 0;
}

