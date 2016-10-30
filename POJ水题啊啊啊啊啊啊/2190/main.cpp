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
* res % 10 > 0 是错的，如果res=-1怎办？？？？
*还是我太菜了
*/
using namespace std;
int n;
char mes[100];

int main()
{
    while(scanf("%s", mes)==1){
    int d = 0, mark = 0;
    for(int i = 0; i < 10; i++){
        if(mes[i] == '?'){
            mark = i;
        }else if(mes[i] == 'X'){
           d += 10 * (10 - i);
           // d += 10 ;
        }else {
            d += (mes[i] - '0') * (10 - i);
        }
    }
    int limit = (mark == 9? 10: 9);
    int res = -1;
    mark = 10 - mark;
    for(int i = 0; i <= limit; i++){
        if((d + i * mark) % 11 == 0){
            res = i; break;
        }
    }
    res != 10? printf("%d", res): printf("X");
    }
    return 0;
}

