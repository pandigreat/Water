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
*д���㷨����2��С��1000000000�����룬������ ����˷�������123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5 
*/
///ע��һ��ǰ���������
using namespace std;

int y, m, d;
string str;
int a[100], b[100];
char str1[100], str2[100];

int main(){

    while(~scanf("%s %s", str1, str2)){
        int res = 0;
        int l1 = strlen(str1), l2 = strlen(str2);
        int i = 0, j = 0;
        while(str1[i] == '0' && i < l1 - 1) i++;
        while(str2[j] == '0' && j < l2 - 1) j++;
        for(int k = i; k < l1; k++)
            a[k] = str1[k] - '0';
        for(int k = j; k < l2; k++)
            b[k] = str2[k] - '0';
        for(int x = i; x < l1; x++)
            for(int y = j; y < l2; y++)
                res += a[x] * b[y];
        printf("%d\n", res);
    }
    return 0;
}

