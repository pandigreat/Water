#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool v[32000] = {0};
vector<int> prime;
void setPrime(){ ///ËØÊıÅĞ¶¨·¨
    v[0] = v[1] = true;
    for(int i = 2; i < 32000; i++){
        for(int j = i << 1; !v[i] && j < 32000; j += i) v[j] = true;
    }
    for(int i = 0; i < 32000; i++)
        if(!v[i]) prime.push_back(i);
}

int main(int argc, char** argv)
{
    setPrime();
    while(~scanf("%d", &n)){
        int res = 0; int m = 0;
        for(; m < prime.size() && n != 1;){
            if(n % prime[m] == 0){
                res++;
                n /= prime[m];
            }else{
                m++;
            }
        }
        printf("%d\n", n==1?res:res+1);
    }

    return 0;
}
