/**
（1）如果出现的是“=”式子，那么两边肯定都是合格的coin，而且false coin肯定不在这个等式里面；

（2）如果出现了不等式，即“<"或者”>"式子，那么可以肯定，在这些式子中肯定都存在一个false coin

（3）如果，一个硬币是false coin，在每个它出现的式子里，都是不等式，而且，要么它总在轻的一方，
　　  要么它总在重的一方但是这个题其坑无比的是，不能从这个角度想，因为给的数据可能根本没有逻
　　  辑，就是说，可能会有自相矛盾的数据，在这种情况下，他的逆命题有可能是真的，首先我们把出
　　  现在等式里的数字排除掉即如果每个不等式里某个数字都出现了，即出现次数等于不等式的个数并
　　  且它总是在重的一方，或者总是在轻的一方，那我们说，这个数字极有可能是false coin，但是还
　　  要统计一下，这样的数字是不是只有一个，如果有两个，或者没有，都没办法判断！
我的思路：对于能通过等式判断出相等的元素，用h【i】=1标记上，意味着false coin绝对不可能是这里面的数字，
对于不等式A[i] < B[i]，设置一个light[i]数组，和一个heavy[i]数组，如果一个数出现在了轻的一边，就让light[i]++;
如果出现在了重的一边，就让heavy[i]++；对于一个false coin，要么他的heavy值等于不等式的个数cas，要么他的light值
等于cas，然后注意不要让ans重复就可以了。
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1000+5;
int n,k,p;
int L[maxn],R[maxn];
int light[maxn],heavy[maxn];
int h[maxn];
char opt;
int cas;
 
int main()
{
    while(cin >> n >> k){
        memset(light,0,sizeof(light));
        memset(heavy,0,sizeof(heavy));
        memset(h,0,sizeof(h));
        cas = 0;
        for(int t = 1;t <= k; ++t){
            cin >> p;
            for(int i = 1; i <= p; ++i)
                cin >> L[i];
            for(int i = 1; i <= p; ++i)
                cin >> R[i];
            cin >> opt;
            if(opt == '='){
                for(int i = 1; i <= p; ++i)
                    h[L[i]] = h[R[i]] = 1;
            }
            else if(opt == '<'){
                cas++;
                for(int i = 1; i <= p; ++i){
                        light[L[i]]++;
                        heavy[R[i]]++;
                }
            }
            else{
                cas++;
                for(int i = 1; i <= p; ++i){
                        heavy[L[i]]++;
                        light[R[i]]++;
                }
            }
        }
        int cnt = 0,ans;
        for(int i = 1; i <= n; ++i)
        {
            if(h[i]==0&&(light[i]==cas||heavy[i]==cas)){
                ans = i;
                cnt++;
            }
        }
        if(cnt!=1) printf("0\n");
        else printf("%d\n", ans);
    }
}