#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

/*
* ฐฅทþมห
*/

using namespace std;
char dict[10010][10];
char scr[10010][10];
char res[10010][10];
int di = 0, si = 0;
char str[10];
int v[200];
int f[200];
inline bool check (int v [], int f[]){
    for(int i = 0; i < 200; i++)
        if(v[i] != f[i])
            return false;
    return true;
}
inline int cmp(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}
int main()
{
    while(scanf("%s", str) != EOF){
        if(!strcmp(str, "XXXXXX")) break;
        strcpy(dict[di++], str);
    }
    while(scanf("%s", str) != EOF){
        if(!strcmp(str, "XXXXXX")) break;
        strcpy(scr[si++], str);
    }
    for(int i = 0; i < si; i++){
        memset(v, 0, sizeof(v));
        int l = strlen(scr[i]);
        for(int j = 0; j < l; j++)
            v[scr[i][j]] ++;

        int ri = 0;
        for(int j = 0; j < di; j++){
            memset(f, 0, sizeof(f));
            int ll = strlen(dict[j]);

            for(int k = 0; k < ll; k++){
                //if(v[dict[j][k]] == 1)
                //    sum ++, v[dict[j][k]];
                f[dict[j][k]]++;
            }
            if(check(v, f)){
                strcpy(res[ri], dict[j]);
                ri ++;
            }

        }
        if(!ri) printf("NOT A VALID WORD\n");
        else{
            qsort(res, ri, sizeof(res[0]), cmp);
            for(int k = 0; k < ri; k++ )
                printf("%s\n", res[k]);
        }
        printf("******\n");
    }

    return 0;
}
