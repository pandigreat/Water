#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
/***
*TLE  motherfucker
*/
using namespace std;

int num;
char in[101];
map<string, int> res;
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
        string s = "";
        int l = strlen(in);
        for(int j = 0; j < l; j++){
            if((in[j] >= 'A' && in[j] <= 'Z'))
                s += fun(in[j]);
            else if(in[j] >= '0' && in[j] <= '9')
                s += in[j];
        }
        //if(res.count(s) == 0) res.insert(pair<string, int>(s, 1));
        //else
        res[s]+= 1;
    }

    map<string, int>::iterator iter, ed;
    for(iter = res.begin(), ed = res.end(); iter != ed; iter++){
        if(iter->second > 1){
            string s = iter->first;
            for(int i = 0; i < 7; i++){
                printf("%c", s[i]);
                if(i == 2) printf("-");
            }
            printf(" %d\n", iter->second);
        }
    }

    return 0;
}
