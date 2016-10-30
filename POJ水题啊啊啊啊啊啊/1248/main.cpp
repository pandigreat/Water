#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
/*
*permutation ²»ÄÜA
*/
using namespace std;
int num;
int i, j, k, n, m;
char mes[10010];
inline int get(char c){
    return c - 'A' + 1;
}
inline bool cmp(char a, char b){
    return a > b;
}
inline int multi(int a, int i){
    return i == 1? a: a * multi(a, i - 1);
}
bool check(){
    if(i != j && i != k && i != n && i != m && j != m && j != k && j != n){
        if(k!=n && k!=m && n !=m) return true;
    }
    return false;
}
int res[10];
int main()
{
    while(scanf("%d %s", &num, mes) != EOF){
        if(!strcmp(mes, "END") && !num) break;
        bool f = false;
        int l = strlen(mes);
        sort(mes, mes + l, cmp);

        for(i = 0; i < l; i++){
            for(j = 0; j < l; j++){
                for(k = 0; k < l; k++){
                    for(n = 0; n < l; n++){
                        for(m = 0; m < l; m++){
                            int t = get(mes[i]) - multi(get(mes[j]), 2) + multi(get(mes[k]), 3) - multi(get(mes[n]), 4) + multi(get(mes[m]), 5);
                            if(t == num && check()){
                                f = true;
                                break;
                            }
                        }
                        if(f)
                            break;
                    }
                    if(f)
                        break;
                }
                if(f)
                    break;
            }
            if(f)
                break;
        }

        if(f){
           // for(int i = 0; i < 5; i++)
            printf("%c%c%c%c%c", mes[i], mes[j], mes[k], mes[n], mes[m]);
            printf("\n");
        }else
            printf("no solution\n");
    }
    return 0;
}
