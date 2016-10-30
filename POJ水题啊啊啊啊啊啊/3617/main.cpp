#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
/**
* 之后考虑的是如果两个字符一样应该做的一个处理
*还是我太菜了
*/
using namespace std;

int n;
char mes[100010];
char res[100010];

int main()
{
    scanf("%d", &n);getchar();
    for(int i = 0; i < n; i++)
        scanf("%c", &mes[i]),getchar();
    int i = 0, j = n - 1, l = 0;
    while(i <= j){

       bool f = true;

       for(int a = i, b = j; a <= b; a++, b--){
            if(mes[a] < mes[b]){
                f = true; break;
            }

            else if(mes[a] > mes[b]){
                f = 0; break;
            }


       }
       l++;
       if(f) putchar(mes[i++]);
       else putchar(mes[j--]);
       if(l % 80 == 0) putchar('\n');
   }

    putchar('\n');
    return 0;
}




