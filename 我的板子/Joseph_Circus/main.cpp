#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;
int n, m, s;
bool v[10010];

int dfs(){
    scanf("%d %d %d", &n, &m, &s);
    memset(v, 0, sizeof(v));
    int k = n -1;
    int i = s;
    while(k){
        int sum = 1;
        while(sum != m){
            while(v[i])
                i = (i + 1) % n;
            sum++;
            i = (i + 1) % n;
                while(v[i])
            i = (i + 1) % n;
        }
        v[i] = true;
        k--;
        while(v[i])
            i = (i + 1) % n;
    }
    for(int i = 0; i < n; ++i){
         if(!v[i])
            return i;
    }

}
int main()
{

    printf("%d", dfs());

    return 0;
}

/**
Լɪ������
���ƹ�ʽ
��f[i]Ϊi��������Ϸ��m�˳�����ʤ���ߵı�ţ����Ľ����Ȼ��f[n]
����
f[1] = 0;
f[i] = (f[i - 1] + m) mod i;

��Ϊ���ƣ����Կ��Բ��ñ���״̬
��������
void solve(){
    int n, m, s, t; //s�ǿ�ʼ��λ�ã�n Ϊ����ʶ��mΪ�����ļ��
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 2; i <= n; i++)
        t = (t + m) % i;
    printf("%d\n", (s + t) % n);
}

*/
