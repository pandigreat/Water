#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
/**
*double����Ǹ�������Ķ�����
*/
using namespace std;
int n;
double mes, res;



int main()
{
    while(scanf("%lf %lf", &mes, &res) == 2){
        printf("%.0f\n", pow(res, 1.0/mes));
    }
    return 0;
}
