#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define inf 0xfffffff
#define N 0x7fff
#define min(x, y) ((x)>(y)? (y): (x))

int n, k;
int i, j, d;
int mes[N][16];
int a, b;

/**
*F[1，0]表示第1个数起，长度为2^0=1的最大值，其实就是3这个数。
*同理 F[1,1] = max(3,2) = 3, F[1，2]=max(3,2,4,5) = 5，F[1，3] = max(3,2,4,5,6,8,1,2) = 8;
*并且我们可以容易的看出F[i,0]就等于A[i]。（DP的初始值）
*这样，DP的状态、初值都已经有了，剩下的就是状态转移方程。
*我们把F[i，j]平均分成两段（因为f[i，j]一定是偶数个数字），从 i 到i + 2 ^ (j - 1) - 1为一段，i + 2 ^ (j - 1)到i + 2 ^ j - 1为一段(长度都为2 ^ (j - 1))。
*用上例说明，当i=1，j=3时就是3,2,4,5 和 6,8,1,2这两段。
*F[i，j]就是这两段各自最大值中的最大值。于是我们得到了状态转移方程F[i, j]=max（F[i，j-1], F[i + 2^(j-1)，j-1]）。
*/

/**
*如我们需要查询的区间为(i,j)，那么我们需要找到覆盖这个闭区间(左边界取i，右边界取j)的最小幂（可以重复，比如查询5，6，7，8，9，我们可以查询5678和6789）。
*因为这个区间的长度为j - i + 1,所以我们可以取k=log2( j - i + 1)，则有：RMQ(A, i, j)=max{F[i , k], F[ j - 2 ^ k + 1, k]}。
*举例说明，要求区间[2，8]的最大值，k = log2（8 - 2 + 1）= 2，
*即求max(F[2, 2]，F[8 - 2 ^ 2 + 1, 2]) = max(F[2, 2]，F[5, 2])；
*/
int main()
{
    srand(time(0));
    if(scanf("%d", &n) == 1 && n < N && n > 0){
        memset(mes, 0x7f, sizeof(mes));
        for(d = 0; d < n; d++)
            mes[d][0] = rand() % inf;
		/*dp方程*/
        for(b = 1; b < 16; b++){
            for(a = 0; a < n; a++){
                if(a + (1 << b) < n)
                    mes[a][b] = min(mes[a][b - 1], mes[a + (1 << (b - 1))][b - 1]);
            }
        }

        printf("The array is: ");
        for(d = 0; d < n; d++)
            printf("%d ", mes[d][0]);

        while(1){
            printf("\nEnter the value of i and j: ");
            if(scanf("%d %d", &i, &j) != 2 && i <= 0 && i > j && j <= 0){
                printf("Input Error\n");
                break;
            }
            int g = log10(j - i + 1) / log10(2.0);
            printf("\nAnswer: %d\n", min(mes[i - 1][g],mes[j-(1<<g)][g]));
        }

    }

    printf("Exit\n");
    return 0;
}
