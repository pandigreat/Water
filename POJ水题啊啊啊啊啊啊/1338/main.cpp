#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*����Ӧ���õĽⷨ��������ˣ���дɶһ��isUgly�ĺ����ж�
*/
using namespace std;

int mes[10010] = {1};
int mi = 1;
int n ;
int idx2 = 0, idx3 = 0, idx5 = 0;
int main()
{

    while(scanf("%d", &n) != EOF){
        if(!n) break;
        if(n <= mi) printf("%d\n", mes[n - 1]);
        else{
            for(mi; mi < n; mi ++){
                int i2 = mes[idx2] * 2;
                int i3 = mes[idx3] * 3;
                int i5 = mes[idx5] * 5;
                int tmp = min(min(i2, i3), i5);
                if(i2 == tmp) idx2++;
                if(i3 == tmp) idx3++;
                if(i5 == tmp) idx5++;
                mes[mi] = tmp;
            }
            printf("%d\n", mes[mi - 1]);
        }
    }


    return 0;
}
