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
void InsertSort(){
	for(int i = 0; i < l - 1; i++){
		int m = i;
		for(int j = i + 1; j < l; j++){
			if(mes[m] > mes[j])
				m = j;
		}
		mes[i] += mes[m];
		mes[m] = mes[i] - mes[m];
		mes[i] = mes[i] - mes[m];
	}
	
}