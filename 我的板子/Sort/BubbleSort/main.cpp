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
void BubbleSort(){
	for(int i = 0; i < l - 1; i++){
		for(int j = l - 1; j > i; j--)
			if(mes[j] < mes[j - 1])
				mes[j] += mes[j - 1], mes[j - 1] = mes[j] - mes[j - 1], mes[j] = mes[j] - mes[j - 1];
	}
}