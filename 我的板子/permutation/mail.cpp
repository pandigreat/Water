#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <algorithm>

using namespace std;

/*
*����STL�����next_permutation��ʵ��˼·���ǵݹ�
 *һ����ԣ���P��[1,n]��һ��ȫ���С�
*������������P=P1P2��Pn=P1P2��Pj-1PjPj+1��Pk-1PkPk+1��Pn
*��������find:����j=max{i|Pi<Pi+1} �Ӻ���ǰ��
������������������k=max{i|Pi>Pj} �Ӻ���ǰ��
������������1��  �Ի�Pj��Pk��
������������2��  ��Pj+1��Pk-1PjPk+1��Pn��ת
������ P1P2P3Pn  ������׼ȷ�ĺ�һ�����С���Ϊ���ݵ�1���Ĳ��ң�������P(i+1) > P(i+2) > . > Pn
 ��ʹ������Pi��Pj�Ľ���,����Ȼ����һ��������һ�����С���������������(�����С������)��Ϊ�������һ������.
          P��= P1P2��Pj-1PkPn��Pk+1PjPk-1��Pj+1��P����һ��
*/
char mes[5000];

void solve(){
    sort(mes, mes + strlen(mes));
	int l = strlen(mes);
    while(true){
        printf("%s\n", mes);
        int s = l - 2, t;
        while(s >= 0){
            if(mes[s] < mes[s + 1]) break;
            s--;
        }
        if(s < 0) break;
        for(t = l - 1; t > s && mes[t] <= mes[s]; t--);
        swap(mes[t], mes[s++]);
        t = l - 1;
        while(t > s) swap(mes[s++], mes[t--]);
    }
}
/**�ݹ�ķ���
**��n= 3����E=��a, b, c��ʱ������ǰ��ĵݹ鶨��ɵ�perm (E) =a.perm ( {b, c} ) +b.perm ( {a,c} ) +c.perm ( {a, b} )��
*ͬ�������յݹ鶨����perm ( {b, c} ) =b.perm ( {c} ) +c.perm ( {b}), ����a.perm ( {b, c} ) = ab.perm ( {c} ) + ac.perm ( {b}) = a b . c + ac.b = (a b c, a c b)��
*ͬ��ɵ�b.perm ( {a, c}) = ba.perm ( {c}) + bc.perm ( {a}) = b a . c + b c . a = (b a c, b c a)��c.perm ( {a, b}) =ca.perm ( {b}) + cb.perm ( {a}) = c a . b + c b . a = (c a b, c b a)��
*����perm (E) = (a b c, a c b, b a c, b c a,c a b, c b a)��ע��a.perm ( {b, c} )ʵ���ϰ����������з�ʽ��abc ��a c b��a �����ǵ�ǰ׺��perm ( {b, c} )�����ǵĺ�׺��
**
*/
void dfs(int i, int j){
	if(i == j) printf("%s\n", mes);
	else{
		for(int k = i; k < j; k++){
			swap(mes[k], mes[i]);
			dfs(i + 1, j);
			swap(mes[k], mes[i]);
		}
	}
}


int main()
{
    scanf("%s", str);
    solve();
    return 0;
}
