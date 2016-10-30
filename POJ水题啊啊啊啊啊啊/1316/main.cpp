#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
bool v[29999];
/*
*Ò»¾ä»°£¬±©Á¦
*/
inline int d(int i){
    int t = i;
    while(i){
        t += i % 10;
        i /= 10;
    }
    return t;
}
//printf("1\n3\n5\n7\n9\n20\n");
int main()
{
    memset(v, 0, sizeof(v));
    int di;

    for(int i = 1; i < 10000; i++){
        int t = i;
        do{
            di = d(t);
            v[di] = true;
            t = di;
        }while(t < 10000);
    }
    for(int i = 1; i < 10000; i++){
        if(!v[i])
            printf("%d\n", i);
    }
    getchar();
    return 0;
}
