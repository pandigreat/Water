#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>
#include <stdlib.h>
#include <algorithm>

using namespace std;

/*
*这是STL里面的next_permutation的实现思路，非递归
 *一般而言，设P是[1,n]的一个全排列。
*　　　　　　P=P1P2…Pn=P1P2…Pj-1PjPj+1…Pk-1PkPk+1…Pn
*　　　　find:　　j=max{i|Pi<Pi+1} 从后往前找
　　　　　　　　　k=max{i|Pi>Pj} 从后往前找
　　　　　　1，  对换Pj，Pk，
　　　　　　2，  将Pj+1…Pk-1PjPk+1…Pn翻转
交换后， P1P2P3Pn  并不是准确的后一个排列。因为根据第1步的查找，我们有P(i+1) > P(i+2) > . > Pn
 即使进行了Pi和Pj的交换,这仍然是这一部分最大的一个排列。将此排列逆序倒置(变成最小的排列)即为所求的下一个排列.
          P’= P1P2…Pj-1PkPn…Pk+1PjPk-1…Pj+1即P的下一个
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
/**递归的法子
**当n= 3并且E=（a, b, c）时，按照前面的递归定义可得perm (E) =a.perm ( {b, c} ) +b.perm ( {a,c} ) +c.perm ( {a, b} )。
*同样，按照递归定义有perm ( {b, c} ) =b.perm ( {c} ) +c.perm ( {b}), 所以a.perm ( {b, c} ) = ab.perm ( {c} ) + ac.perm ( {b}) = a b . c + ac.b = (a b c, a c b)。
*同理可得b.perm ( {a, c}) = ba.perm ( {c}) + bc.perm ( {a}) = b a . c + b c . a = (b a c, b c a)，c.perm ( {a, b}) =ca.perm ( {b}) + cb.perm ( {a}) = c a . b + c b . a = (c a b, c b a)。
*所以perm (E) = (a b c, a c b, b a c, b c a,c a b, c b a)。注意a.perm ( {b, c} )实际上包含两个排列方式：abc 和a c b，a 是它们的前缀，perm ( {b, c} )是它们的后缀。
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
