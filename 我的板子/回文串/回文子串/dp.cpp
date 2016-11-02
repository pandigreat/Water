#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
///这个是求最长回文子串的，不是最长回文子序列
/// dp[i][j] = {if(dp[i] == dp[j] then dp[i+1][j-1] else 0}
using namespace std;

int m, n;
string str;
bool dp[10010][10010];
void solve(){
    memset(dp, 0, sizeof(dp));
    int s, maxl = 0;
    int l = str.length();
    for(int i = 0; i < l; i ++){ ///预处理一下， 处理abcdd这种例子
        dp[i][i] = 1;
        if(i < l - 1 && str.at(i) == str.at(i + 1)){
            dp[i][i + 1] = 1;
            s = i;
            maxl = 2;
        }
    }
    ///在计算每个最长的长度是多少
    for(int len = 3; len <= l; len++){
        for(int i = 0; i <= l - len; i++){ ///开始算的位置是多少
            int j = i + len - 1; ///结束的位置
            if(dp[i + 1][j - 1] && str.at(i) == str.at(j)){
                dp[i][j] = 1;
                maxl = len;
                s = i;
            }
        }
    }

    if(maxl > 1) cout << str.substr(s, maxl) << endl;
    else printf("Nop\n");
}

int main(){

    while(cin >> str){
        solve();
    }
    return 0;
}

