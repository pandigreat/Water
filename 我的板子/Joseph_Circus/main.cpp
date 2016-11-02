#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;
int n, m, s;
bool v[10010];

int dfs(){
    scanf("%d %d %d", &n, &m, &s);
    memset(v, 0, sizeof(v));
    int k = n -1;
    int i = s;
    while(k){
        int sum = 1;
        while(sum != m){
            while(v[i])
                i = (i + 1) % n;
            sum++;
            i = (i + 1) % n;
                while(v[i])
            i = (i + 1) % n;
        }
        v[i] = true;
        k--;
        while(v[i])
            i = (i + 1) % n;
    }
    for(int i = 0; i < n; ++i){
         if(!v[i])
            return i;
    }

}
int main()
{

    printf("%d", dfs());

    return 0;
}

/**
约瑟夫问题
递推公式
让f[i]为i个人玩游戏报m退出最后的胜利者的编号，最后的结果自然是f[n]
服了
f[1] = 0;
f[i] = (f[i - 1] + m) mod i;

因为递推，所以可以不用保存状态
代码如下
void solve(){
    int n, m, s, t; //s是开始的位置，n 为总认识，m为报数的间隔
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 2; i <= n; i++)
        t = (t + m) % i;
    printf("%d\n", (s + t) % n);
}

*/
