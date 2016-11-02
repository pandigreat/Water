#include <stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N 500100
#define ull unsigned long long
///字符串处理一般都容易超时
///方法之一就是利用int 数组
int mes[N];
int n;

int main(int argc, char** argv)
{
    while(~scanf("%d", &n)){
        memset(mes, 0, sizeof(mes));
        mes[0] = 1;
        int l = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < l; j++) mes[j] *= i;
            for(int j = 0; j < l; j++){
                if(mes[j] > 9){
                    mes[j + 1] += mes[j] / 10;
                    mes[j] %= 10;
                    if(j + 1 == l) l++;
                }
            }
        }
        for(int i = l - 1; i >= 0; i--) printf("%d", mes[i]);
        printf("\n");
    }
    return 0;
}
