/**
��1��������ֵ��ǡ�=��ʽ�ӣ���ô���߿϶����Ǻϸ��coin������false coin�϶����������ʽ���棻

��2����������˲���ʽ������<"���ߡ�>"ʽ�ӣ���ô���Կ϶�������Щʽ���п϶�������һ��false coin

��3�������һ��Ӳ����false coin����ÿ�������ֵ�ʽ������ǲ���ʽ�����ң�Ҫô���������һ����
����  Ҫô�������ص�һ���������������ޱȵ��ǣ����ܴ�����Ƕ��룬��Ϊ�������ݿ��ܸ���û����
����  ��������˵�����ܻ�������ì�ܵ����ݣ�����������£������������п�������ģ��������ǰѳ�
����  ���ڵ�ʽ��������ų��������ÿ������ʽ��ĳ�����ֶ������ˣ������ִ������ڲ���ʽ�ĸ�����
����  �����������ص�һ�����������������һ����������˵��������ּ��п�����false coin�����ǻ�
����  Ҫͳ��һ�£������������ǲ���ֻ��һ�������������������û�У���û�취�жϣ�
�ҵ�˼·��������ͨ����ʽ�жϳ���ȵ�Ԫ�أ���h��i��=1����ϣ���ζ��false coin���Բ�����������������֣�
���ڲ���ʽA[i] < B[i]������һ��light[i]���飬��һ��heavy[i]���飬���һ���������������һ�ߣ�����light[i]++;
������������ص�һ�ߣ�����heavy[i]++������һ��false coin��Ҫô����heavyֵ���ڲ���ʽ�ĸ���cas��Ҫô����lightֵ
����cas��Ȼ��ע�ⲻҪ��ans�ظ��Ϳ����ˡ�
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