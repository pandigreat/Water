#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<queue>
#include<vector>


#define max((x), ((y)) (x) > (y)?  (x): (y)
#define min ((x), (y))) (x) < (y)? (x): (y)
#define mid((x), (y), (z))) min(max((x), (y))), max((x), (z))))
#define MaxInt 0x7fffffff

/**
 快速幂算法——可迅速求出a^b。其主要理论依据如下：

        1，当b为偶数时，a^b可以转为a^2的b/2次方。

        2，当b为奇数时，a^b可以转为a^2的b/2次方，再乘以a。

**/
using namespace std;
typedef long long ll;

ll dfs(ll x, ll y){
	ll res = 0;
	while(y){
		if(y & 0x1 == 1) 
			res = (res + x) % MaxInt;
		x = (x * x) % MaxInt;
		y >>= 1;
	}
}

int main(){
	
	
	return 0;
}