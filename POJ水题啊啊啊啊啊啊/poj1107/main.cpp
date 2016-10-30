#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#define PII pair<int, int>
using namespace std;

int k1, k2, k3;
char mes[10010];
int arr1[10010], arr2[10010], arr3[10010];
char res[10010];
void rota(int mess[], int k, int l){
        for(int i = 0; i < l; i++)
            res[mess[(i + k) % l]] = mes[mess[i]];
}
int main(){
    int a, b, s;
    while(~scanf("%d %d %d", &k1, &k2, &k3)){
        if(!k1 && !k2 && !k2) break;
        scanf("%s", mes);
        int l = strlen(mes);
        int l1 = 0, l2 = 0, l3 = 0;
        for(int i = 0; i < l; i++){
            if(mes[i] >= 'a' && mes[i] <= 'i') arr1[l1++]  = i;
            else if(mes[i] >= 'j' && mes[i] <= 'r') arr2[l2++]  = i;
            else arr3[l3++] = i;
        }
        k1 %= l1; k2 %= l2; k3 %= l3;
        rota(arr1, k1, l1 );
        rota(arr2, k2, l2 );
        rota(arr3, k3, l3 );
        printf("%s\n", res);
        memset(res, '\0', sizeof(res));
    }

    return 0;
}
