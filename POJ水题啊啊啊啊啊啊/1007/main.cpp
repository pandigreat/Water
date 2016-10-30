#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct a{
    char *s;
    int n;
};
bool cmp(a c, a b){
    return (c.n ) < (b.n);
}


int l, n;
a in[104];

int main(){
    for(int i = 0; i < 110; i++){
        in[i].s = (char*)malloc(sizeof(char)*110);
        memset(in[i].s, '\0', sizeof(in[0].s));
        in[i].n = 0;
    }
    scanf("%d %d", &l, &n);
    for(int i = 0; i < n; i++){
        scanf("%s", in[i].s);
        int t = 0;
        for(int j = 0; j < l - 1; j++){
            for(int k = j + 1; k < l; k++)
                if(in[i].s[j] > in[i].s[k])
                t++;
        }
        in[i].n = t;
    }
    sort(in, in + n, cmp);
    for(int i = 0; i < n; i++)
        printf("%s\n", in[i].s);
    getchar();
    for(int i = 0; i < 110; i++)
        free(in[i].s);
    return 0;
}
