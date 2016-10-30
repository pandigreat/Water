#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*这个题 的一个坑就是那啥atoi，itoa不能用
*看懂题就会做，哎英文不行
*加强一下string的操作,注意一下，某些字符没有被吃掉比如\n
*醉哎
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
        getchar();//吃掉\n
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