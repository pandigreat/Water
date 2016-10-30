#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*妈的，这道题不用想太难了
*Sam从1开始而Ella从N开始就行了，不用考虑循环队列
*/
using namespace std;
int n;
int mes[100];
int l, r;
int lp, rp;
int lv, rv;
int hv;
int last;
void lf(){
    if(hv < n && lv > rv){
        hv ++;
        rv += mes[r];
        r = (r + n - 1) % n;
        last = 0;
    }
}
void rf(){
    if(hv < n && lv <= rv){
        hv ++;
        lv += mes[l];
        l = (l + 1) % n;
        last = 1;
    }
}

int main()
{
    while(scanf("%d", &n) != EOF){
        if(!n) break;
        int s = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &mes[i]);
            s += mes[i];
        }
        if(s % 0x1 == 1){
            printf("No equal partitioning.\n");
            continue;
        }
        bool flag = false;

            lv = rv = 0;
            hv = 0;
            l = 0; r = n - 0 - 1;
            while(hv < n){
                rf();
                lf();
            }
            if(lv == rv){
                flag = true;
                if(last){
                    /*rp = (r + 2) % n;
                    lp = (rp + n - 1) % n;*/
                    lp = l;
                    if(lp < n)
                        rp = lp + 1;
                    else
                        rp = 1;
                }else{
                    /*lp = l;
                    rp = (l + 1) % n;*/
                    lp = l;
                    if(lp < n)
                        rp = lp + 1;
                    else
                        rp = 1;
                }
            }

        if(flag){
            printf("Sam stops at position %d and Ella stops at position %d.\n", lp, rp);
        }else{
            printf("No equal partitioning.\n");
        }
    }
    return 0;
}
