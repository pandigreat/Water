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
* 之后考虑的是如果两个字符一样应该做的一个处理
*还是我太菜了
*/
using namespace std;

int n;

void Hanoi(int n, char a, char b, char c){
    if(n == 1)
        printf("move %d from %c to %c\n", n, a, c);
    else{
        Hanoi(n - 1, a, c, b);
        printf("move %d from %c to %c\n", n, a, c);
        Hanoi(n - 1, b, a, c);
    }

}


int main()
{
    Hanoi(3, 'a', 'b', 'c');

    return 0;
}




