#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
/**
*����� �����ʽ�������ʽ������������iomanip ��fixed����seprecison�ͺ��ˣ���������
*��ʽ�������lf�ʹ�����f���ǶԵģ�����������ȥ������
*ʲô��
*��
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




