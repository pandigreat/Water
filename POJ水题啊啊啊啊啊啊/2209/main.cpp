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
* 看看提示就明白题目的意思了
*还是我太菜了
*/
using namespace std;
int n;
int mes[120];
int m;
int main()
{
    scanf("%d %d", &n, &m); bool f = false;
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &mes[i]);
        if(pow(mes[i], m) > 0){
            f = true;
            sum += pow(mes[i], m);
        }
    }
    printf("%d\n", sum);
    return 0;
}
