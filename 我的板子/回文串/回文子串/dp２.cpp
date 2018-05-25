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
���� X[0 ... n-1]  �Ǹ��������У�����Ϊn.  �� L(0,n-1) ��ʾ ���� X[0 ... n-1] ������������еĳ��ȡ�

1. ���X�����һ��Ԫ�غ͵�һ��Ԫ������ͬ�ģ���ʱ��L(0, n-1) = L(1, n-2) + 2 ,  ���� ��BBABCBCAB�� Ϊ������һ�������һ����ͬ����� L(1,n-2) �ͱ�ʾ��ɫ�Ĳ��֡�

2. �������ͬ��L(0, n-1) = MAX ( L(1, n-1) ,  L(0, n-2) )�� �ԡ�BABCBCA�� Ϊ����L(1,n-1)��Ϊȥ����һ��Ԫ�ص������У�L(0, n-2)Ϊȥ�����һ��Ԫ�ء�

��������Ĺ�ʽ�����Ժ����׵�д������ĵݹ����
*/
/**
�����ݹ������������ظ��ļ����
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

