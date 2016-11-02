#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

int heap [20010];
int l;

void adjustHeap( int i, int length){
    int j = i;
    for(; j < length; j = (j == 0)? 1: 2 *j){
        int idx = j, l = 2 * j + 1, r = 2 * j + 2;
        if(l < length && heap[idx] < heap[l]) idx = l;
        if(r < length && heap[idx] < heap[r]) idx = r;
        if(idx != j) swap(heap[j], heap[idx]);
    }
}
void solve(){
    for(int i = l / 2; i >= 0; i --){adjustHeap( i, l);}
    for(int i = l - 1; i > 0; i --)
        swap(heap[0], heap[i]), adjustHeap( 0, i );
}
int main()
{
    FILE* fp;
    fp = fopen("1.txt", "r");
    fscanf(fp, "%d", &l);
    for(int i = 0; i < l; i++)
        fscanf(fp, "%d", &heap[i]);
    solve();
    while(--l >= 0)
        printf("%d ",heap[l]);
    fclose(fp);
    return 0;
}
