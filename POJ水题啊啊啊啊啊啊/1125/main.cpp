/*
首先，题目可能有多组测试数据，每个测试数据的第一行为经纪人数量N（当N=0时，输入数据结束），然后接下来N行描述第i（1<=i<=N）个经纪人与其他经纪人的关系（教你如何画图）。每行开头数字M为该行对应的经纪人有多少个经纪人朋友（该节点的出度，可以为0），然后紧接着M对整数，每对整数表示成a,b,则表明该经纪人向第a个经纪人传递信息需要b单位时间（即第i号结点到第a号结点的孤长为b），整张图为有向图，即弧Vij 可能不等于弧Vji（数据很明显，这里是废话）。当构图完毕后，求当从该图中某点出发，将“消息”传播到整个经纪人网络的最小时间，输出这个经纪人号和最小时间。最小时间的判定方式为——从这个经纪人（结点）出发，整个经纪人网络中最后一个人接到消息的时。如果有一个或一个以上经纪人无论如何无法收到消息，
输出“disjoint”（有关图的连通性，你们懂得，但据其他同学说，POJ测试数据中不会有，就是说，你不判定，一样能过，题目数据够水的）。
*/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x7f7f7f7f
#define ull unsigned long long
#define ll long long
#define PII pair<int, int>
#define P pair<int, PII>
#define ui unsigned int
using namespace std;

priority_queue<PII> q;
vector<PII> vec[110];
int dist[110];
int n;
unsigned int mes[110][110], pre[110];

int getf(int i){
    return i == pre[i]? i: getf(pre[i]);
}

void union_set(int i, int j){
    i = getf(i);
    j = getf(j);
    if(i - j)
        pre[i] = j;
}

int main()
{
    while(~scanf("%d", &n) && n){
        memset(mes, 0x7f, sizeof(mes));
        for(int i = 0; i < 110; i++)
            pre[i] = i;
        for(int i = 1; i <= n; i++){
            int num, a, b;
            scanf("%d", &num);
            for(int j = 0; j < num; j++){
                scanf("%d %d", &a, &b);
                mes[i][a] = b;
                union_set(i, a);
            }
        }
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    mes[i][j] = min(mes[i][j], mes[i][k] + mes[k][j]);
        int ans = inf, pos;
        for(int i = 1; i <= n; i++){
            int tmp = 0;
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(mes[i][j] > tmp)
                    tmp = mes[i][j];
            }
            if(ans > tmp)
                ans = tmp, pos = i;
        }
        printf("%d %d\n", pos, ans);
    }
}


