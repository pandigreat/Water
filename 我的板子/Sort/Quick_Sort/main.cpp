#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;
int arr [20010];
int l;

int part(int i, int j){
    int sen = arr[i];
    while(i < j){
        while(i < j && sen < arr[j]) j--;
        if(i < j) arr[i++] = arr[j];
        while(i < j && arr[i] <= sen) i++;
        if(i < j) arr[j--] = arr[i];
    }arr[i] = sen;
    return i;
}
void qSort(int i, int j){
    if(i < j){
        int p = part(i, j);
        qSort(i, p);
        qSort(p + 1, j);
    }
}
int main()
{
    FILE* fp;
    fp = fopen("1.txt", "r");
    fscanf(fp, "%d", &l);
    for(int i = 0; i < l; i++)
        fscanf(fp, "%d", &arr[i]);
    qSort(0, l - 1);
    while(--l >= 0)
        printf("%d ",arr[l]);
    fclose(fp);
    return 0;
}
