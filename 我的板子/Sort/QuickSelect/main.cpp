#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define inf 0x7fffffff


int n, k;
int i, j, k;
int *mes;

int part(int a, int b){
    int p = mes[a];
    while(a < b){
        while(a < b && p < mes[b]) b--;
        if(a < b) mes[a] = mes[b];
        while(a < b && p >= mes[a]) a++;
        if(a < b) mes[b] = mes[a];
    }
    mes[a] = p;
    return a;
}

int solve(int k){
    int piv = -1;
    int a = 0;
    int b = n - 1;
    while(1){
        piv = part(a, b);
        if(piv == k - 1)
            break;
        else if(piv < k - 1)
            a = piv + 1;
        else
            b = piv - 1;
    }
    return mes[piv];
}