
/*题目描述：

    某人有8角的邮票5张，1元的邮票4张，1元8角的邮票6张，用这些邮票中的一张或若干张可以得到多少种不同的邮资？
*/

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
///
using namespace std;
int m, n;
char mes[10010];
//int dp[10010][10010];
int arr[] = {8,8,8,8,8, 10,10,10,10,18,18,18,18,18,18};
set<int> res;
#define N (1 << 15)
int main(){
    int tmp  = 0;
    for(int i = 1; i < N; i++){
        int tres = 0; tmp = 0;
        for(int j = 0; j < 15; j++){
            tmp = 1 << j;
            if(tmp & i)
                tres += arr[j];
        }
        res.insert(tres);
    }

    printf("%d\n", res.size());
    return 0;
}







