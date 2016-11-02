#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;
int mes[100100];
int l;
int a[100100];

void merge(int mes[], int s, int e, int a[]){
	int m = (s + e) / 2, k = s;
	int i = s, j = m + 1;
	while(i <= m && j <= e){
		if(mes[i] < mes[j])
			a[k++] = mes[i++];
		else a[k++] = mes[j++];
	}
	while(i <= m) a[k++] = mes[i++];
	while(j <= e) a[k++] = mes[j++];
	for(int n = s; n <= e; n++)
		mes[n] = a[n]; 
}

void MergeSort(int mes[], int s, int e, int a[]){
	if(s = e) mes[s] = a[s];
	else {
		int m = (s + e) / 2;
		MergeSort(mes, s, m, a);
		MergeSort(mes, m + 1, e, a);
		merge(mes, s, e, a);
	}
}