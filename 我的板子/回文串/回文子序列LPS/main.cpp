#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
///�����������������еģ�
///
using namespace std;
int m, n;
char mes[10010];
int dp[10010][10010];
///�������lcs,�ݹ�ķ������ظ�����ĵط�
int lps(const char* a, int i, int j){
    if(i == j) return 1; ///����Ϊ1
    if(i > j) return 0; ///ֻ�Ǽ���[i...j]֮��ĳ��ȶ��Ѱ�
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
    
    printf("%d\n", dp[0][l - 1]);///�����Ӵ�mes[0][l - 1] �Ľ��
}

int main(){

    while(scanf("%s", mes) == 1){
        printf("%d\n", lps(mes, 0, strlen(mes) - 1));
    }
    return 0;
}

