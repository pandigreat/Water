/**
*
在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下:
距离s           票价
0<S<=L1         C1
L1<S<=L2        C2
L2<S<=L3        C3
输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9。
每两个站之间的距离不超过L3。
当乘客要移动的两个站的距离大于L3的时候，可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。
现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。
然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。
根据输入，输出乘客从A到B站的最小花费。
*/

#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
#define N 100100
#define ull unsigned long long
ull c1, c2, c3, l1, l2, l3;
ull a, b;
ull v[N] = {0};
ull dp[N];
ull get(int i, int j){
    if(v[j] - v[i] <= l1) return c1;
    else if(v[j] - v[i] <= l2) return c2;
    return c3;
}

int main(int argc, char** argv)
{

    while(~scanf("%lld %lld %lld %lld %lld %lld", &l1, &l2, &l3, &c1, &c2, &c3)){
        memset(dp, 0x7f, sizeof(dp));
        scanf("%lld %lld %lld", &a, &b, &n);
        for(int i = 2; i <= n; i++) scanf("%lld", v + i);
        dp[a] = 0;
        for(int i = a; i < n; i ++) {
            for(int j = i + 1; j <= b && v[j] - v[i] <= l3;j++){
                dp[j] = min(get(i, j) + dp[i], dp[j]);
            }
        }
        printf("%lld\n", dp[b]);

    }

    return 0;
}

