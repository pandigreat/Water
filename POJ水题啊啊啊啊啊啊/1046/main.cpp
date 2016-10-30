#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

struct d{
    int x;
    int y;
    int z;
    int d;
};

int a, b, c;

d mes[16];
d test;

int cou(d a, d b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

int main(){

    for(int i = 0; i < 16; i ++){
        scanf("%d %d %d", &mes[i].x, &mes[i].y, &mes[i].z);
       // mes[i].d = mes[i].x * mes[i].x + mes[i].y * mes[i].y + mes[i].z * mes[i].z;
    }
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        if(a == -1 && b == -1 && c == -1) break;
        test.x = a; test.y = b; test.z = c;
        //test.d = test.x * test.x + test.y * test.y + test.z * test.z;
        int m = 100000000, g = 0;
        for(int i = 0; i < 16; i++){
            int di = cou(test, mes[i]);
            if((di) < m)
                m = (di), g = i;
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", test.x, test.y, test.z, mes[g].x, mes[g].y, mes[g].z);
    }
    return 0;
}
