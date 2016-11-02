#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <set>
#include <vector>
#define ull unsigned long long
#define PLL pair<ull, ull>
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
vector<PLL> vec[10010];
ull pre[10010], dist[10010];
priority_queue<PLL> q;

void dijik(int s){
    memset(dist, 0x7f, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    dist[s] = 0;
    pre[s] = s;
    q.push(PLL(0, s));
    while(!q.empty()){
        PLL pll = q.top();
        q.pop();
        int st = pll.second;
		if(dist[st] < pll.first) 
			continue;
        for(int i = 0; i < vec[st].size(); i++){
            PLL t = vec[st][i];
            if(dist[t.second] > dist[st] + t.first){
                dist[t.second]  = dist[st] + t.first;
                pre[t.second] = st;
                q.push(t);
            }
        }
    }
}

void print(int e, int t){
    if(e != pre[e]) print(pre[e], e);
    printf("%lld %lld %lld\n", e, t, dist[t]);
}
int main()
{
    while(~scanf("%lld%lld%lld%lld", &n, &m, &s, &t)){
        ull a, b, c;
        for(ull i = 0; i < m; i++){
            scanf("%lld%lld%lld", &a, &b, &c);
            vec[a].push_back(PLL(c, b));
            vec[b].push_back(PLL(c, a));
        }
        dijik(s);
        printf("%lld\n", dist[t]);
    }
    return 0;
}


