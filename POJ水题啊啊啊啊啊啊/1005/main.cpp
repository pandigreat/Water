#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
/**
*����R*R�е�R����������������������
*/
using namespace std;
int n;
float x, y;

int main()
{

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%f %f", &x, &y);
        printf("%d\n", (int)((x * x + y * y) * acos(-1) / 100) + 1);
    }

    return 0;
}
