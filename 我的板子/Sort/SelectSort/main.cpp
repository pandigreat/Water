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
void SelectSort(){
	for(int i = 1; i < l; i++){
		int j = i, tmp = mes[i];
		while(j > 0 && tmp < mes[j - 1])
			mes[j--] = mes[j - 1];
		mes[j] = tmp;
	}
	
}