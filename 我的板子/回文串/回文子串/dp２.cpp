#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#define inf 2000000000
#define ll unsigned long long
/**
假设 X[0 ... n-1]  是给定的序列，长度为n.  让 L(0,n-1) 表示 序列 X[0 ... n-1] 的最长回文子序列的长度。

1. 如果X的最后一个元素和第一个元素是相同的，这时：L(0, n-1) = L(1, n-2) + 2 ,  还以 “BBABCBCAB” 为例，第一个和最后一个相同，因此 L(1,n-2) 就表示蓝色的部分。

2. 如果不相同：L(0, n-1) = MAX ( L(1, n-1) ,  L(0, n-2) )。 以”BABCBCA” 为例，L(1,n-1)即为去掉第一个元素的子序列，L(0, n-2)为去掉最后一个元素。

有了上面的公式，可以很容易的写出下面的递归程序：
*/
/**
画出递归树，发现有重复的计算点
*/
using namespace std;

int lps(int *num, int i , int j){
	if (i == j ) return 1;
	if (i > j) return 0;
	if (num[i] == num[j])
		return lps(num, i+1, j-1) + 2;
	return max(lps(num, i+1, j), lps(num, i, j-1));
	
}

int main(){

    while(cin >> str){
        solve();
    }
    return 0;
}

