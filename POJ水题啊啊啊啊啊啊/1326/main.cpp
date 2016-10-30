#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*1. Presentation Error 2. x.5 should be x + 1;
*/
using namespace std;
char mes[1010];
char c[1010];
int mi;
int res;

inline int h(int c){
    return c & 0x1 == 1? c / 2 + 1: c / 2;
}

int main()
{
    while(scanf("%s", mes) != EOF){
        if(!strcmp(mes, "#")) break;
        res = 0;
        do{
            scanf("%s", mes);
            scanf("%d", &mi);
            scanf("%s", c);
            if(!strcmp("F", c)){
                mi += mi;
            }else if(!strcmp("B", c)){
                int t = h(mi);
                mi += t;
            }else{
                if(mi < 500)
                    mi = 500;
            }
            res += mi;
            scanf("%s", mes);
        }while(strcmp(mes, "0"));
        printf("%d\n", res);
    }


    return 0;
}
