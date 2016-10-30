    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <string.h>
    #include <map>
    #include <set>
    #include <queue>
    #include <stack>
    #include <algorithm>

    #define max(x, y) (x)>(y)?(x):(y)
	/**
	*此题关键：1. 贪心+优先队列
	*2. 就是-1跳出那里注意一下,
	*/
    using namespace std;

    typedef struct ty{
        int w;
        int l;
    }ty;
    int l, p;
    int n;
    bool cmp(ty a, ty b){
        return b.w > a.w;
    }
    int main()
    {

        while(scanf("%d", &n) != EOF){
        priority_queue <int, vector<int>, less<int> > q;
        ty dp[10010];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >= 0; i --)
            scanf("%d %d", &dp[i].w, &dp[i].l);
        scanf("%d %d", &l, &p);

        for(int i = 0; i < n; i++){
            dp[i].w = l - dp[i].w;
        }
        dp[n].w = l; dp[n].l = 0;
        sort(dp, dp + n + 1, cmp);
        int pos = 0, res = 0, r = p;
        for(int i = 0; i <= n; i++){
            int d = dp[i].w - pos;
            while(r - d < 0){
                if(q.empty()){
                    res = -1;
                    break;
                }
                r += q.top();
                q.pop();
                res ++;
            }
            if(res == -1) break;
            r -= d;
            pos = dp[i].w;
            q.push(dp[i].l);
        }
        printf("%d\n", res);
    }
        return 0;
    }




