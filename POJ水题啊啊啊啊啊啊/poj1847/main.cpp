#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <deque>
#define PII pair<int, int>
#define P pari<int, PII>
#define INF 0x11111111

using namespace std;
int mes[110][110];
deque<int> step[110][110];
int n, a, b;


/**
就是有n个交叉点，就当做有n个点就行，然后这些点和其他点有些路径，每个点是一个开关，开关只能有一个方向走一条路，而第一个数就是默认的开关指向，不用旋转。

这单犯了个错，就是默认的指向实际上只需要旋转0次，而其他路径只需要旋转1次，无论是哪条，只需1次，当初以为，第二个1次，第3个2次。



题目给的实例

3 2 1 //有3个开关点，计算从第二个到第一个最少需要旋转几次

2 2 3//第1个开关可以通向2 和3 ，通向2不需要旋转，通向3需要旋转1次

2 3 1//第2个开关可以通向3 和1， 通向3不需要旋转，通向1需要旋转1次
*/
int main()
{
    int n,a,b,k,x;
    while(scanf("%d %d %d",&n,&a,&b)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
                mes[i][j]=mes[j][i]=INF;
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&k);
            for(int j=1; j<=k; j++)
            {
                scanf("%d",&x);
                mes[i][x]=j==1?0:1;
            }
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                    mes[i][j]=min(mes[i][j],mes[i][k]+mes[k][j]);
            }
        }
        if(mes[a][b]==INF)
            printf("-1\n");
        else
            printf("%d\n",mes[a][b]);
    }
    return 0;
}
