/**
*
��ĳ����·����N����վ�������־����·�̣�L1��L2��L3,��Ӧ�ļ۸�ΪC1,C2,C3.���Ӧ��ϵ����:
����s           Ʊ��
0<S<=L1         C1
L1<S<=L2        C2
L2<S<=L3        C3
���뱣֤0<L1<L2<L3<10^9,0<C1<C2<C3<10^9��
ÿ����վ֮��ľ��벻����L3��
���˿�Ҫ�ƶ�������վ�ľ������L3��ʱ�򣬿���ѡ����м�һ��վ�³���Ȼ����Ʊ���ϳ������Գ˿��������������ٻ�������Ʊ��
���ڸ���һ�� L1��L2��L3��C1��C2,C3��Ȼ����A B��ֵ����ֱ�Ϊ�˿��ó̵���ʼվ���յ�վ��
Ȼ������N��NΪ����·�ϵ��ܵĻ�վ��Ŀ��Ȼ������N-1���������ֱ����Ӹ���·�ϵĵ�һ��վ������2��վ����3��վ����������N��վ�ľ��롣
�������룬����˿ʹ�A��Bվ����С���ѡ�
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

