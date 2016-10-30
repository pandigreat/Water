#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;
int n;
int a, b;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        printf("Scenario #%d:\n", i + 1);
        int s = a * b;
        if(s % 2 == 0)printf("%d.00\n", s);
        else printf("%d.41\n", s);
    }
    return 0;
}
