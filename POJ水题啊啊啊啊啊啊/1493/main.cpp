#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*����� ��һ���Ӿ�����ɶatoi��itoa������
*������ͻ�������Ӣ�Ĳ���
*��ǿһ��string�Ĳ���,ע��һ�£�ĳЩ�ַ�û�б��Ե�����\n
*��
*/
using namespace std;

int n;

int cnt(string s){
    int d = 0;
    for(int i = 0; i < s.length(); i++)
        if(s[i]== ' ')
            d++;
    return d;
}
int main()
{
    while(scanf("%d", &n) != EOF && n){
        int m = 99999; int res = 0;
        getchar();//�Ե�\n
        string str = "";int t;
        for(int i = 0; i < n; i++){
            getline(cin, str);
            t = cnt(str);
            res += t;
            if(t < m)
                m = t;
        }
        printf("%d\n", res - m * n);
    }
    return 0;
}