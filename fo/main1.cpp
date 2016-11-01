#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#define PII pair<int, int>
#define ll long long
#define ull unsigned long long
#define ui unsigned int

using namespace std;

int a, b, c;
int main()
{
    while(~scanf("%d%d%d", &a, &b, &c)){
        int ma = max(max(a, b), c);
        int mi = min(min(a, b), c);
        printf("%d\n", ma - mi);
    }
    return 0;
}
