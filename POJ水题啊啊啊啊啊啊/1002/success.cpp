#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/**
*他娘的要改成int才避免字符串处理的问题，还有一个no duplicates 。。。。。。
*老子服了
*
*/
using namespace std;

int num;
char in[101];
map<int, int> res;
inline char fun(char a)
{
    switch(a)
    {
    case 'A':
    case 'B':
    case 'C': return '2';
    case 'D':
    case 'E':
    case 'F': return '3';
    case 'G':
    case 'H':
    case 'I': return '4';
    case 'J':
    case 'K':
    case 'L': return '5';
    case 'M':
    case 'N':
    case 'O': return '6';
    case 'P':
    case 'R':
    case 'S': return '7';
    case 'T':
    case 'U':
    case 'V': return '8';
    case 'W':
    case 'X':
    case 'Y': return '9';
    default: return a;
    }
}
int main()
{

    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        scanf("%s", in);
        int s = 0;
        int l = strlen(in);
        for(int j = 0; j < l; j++){
            if((in[j] >= 'A' && in[j] <= 'Z'))
                s = s * 10 + fun(in[j]) - '0';
            else if(in[j] >= '0' && in[j] <= '9')
                s = s * 10 + in[j] - '0';
        }
        res[s]+= 1;
    }

    map<int, int>::iterator iter, ed;
    bool flag = false;
    for(iter = res.begin(), ed = res.end(); iter != ed; iter++){
        if(iter->second > 1){
            int s = iter->first;
            flag = true;
            printf("%03d-%04d %d\n", s/10000, s % 10000, iter->second);

        }
    }
    if(!flag) printf("No duplicates.\n");

    return 0;
}
