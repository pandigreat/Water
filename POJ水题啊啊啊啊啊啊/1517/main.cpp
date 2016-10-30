#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
/**
*这个题 输出格式啊输出格式。。。。用了iomanip 的fixed还有seprecison就好了？？？？？
*格式化输出用lf就错了用f才是对的？？？？？我去。。。
*什么鬼啊
*醉哎
*/
using namespace std;

int n;
double res ;
int f(int i ){
    return i == 1 || i == 0? 1: i * f(i - 1);
}
int main()
{
    printf("n e\n");
    printf("- -----------\n");
    res = 2.500000000000;
    printf("0 1\n1 2\n2 2.5\n");
    for(int i = 3; i < 10; i++){
        res += 1.0 / f(i);
        printf("%d %.9f\n", i, res);
        //cout<< i << " " << fixed << setprecision(9) << res << endl;
    }

    return 0;
}




