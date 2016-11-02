#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
///�������������Ӵ��ģ����������������
/// dp[i][j] = {if(dp[i] == dp[j] then dp[i+1][j-1] else 0}
using namespace std;

int m, n;
string str;
bool dp[10010][10010];
void solve(){
    memset(dp, 0, sizeof(dp));
    int s, maxl = 0;
    int l = str.length();
    for(int i = 0; i < l; i ++){ ///Ԥ����һ�£� ����abcdd��������
        dp[i][i] = 1;
        if(i < l - 1 && str.at(i) == str.at(i + 1)){
            dp[i][i + 1] = 1;
            s = i;
            maxl = 2;
        }
    }
    ///�ڼ���ÿ����ĳ����Ƕ���
    for(int len = 3; len <= l; len++){
        for(int i = 0; i <= l - len; i++){ ///��ʼ���λ���Ƕ���
            int j = i + len - 1; ///������λ��
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

