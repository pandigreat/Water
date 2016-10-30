#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int ri;
char res[10010][10010];
char mes[10010];
char decode(char c){
    if(isalpha(c))
        return (c - 'A' + 'V' - 'A') % 26 + 'A';
    return c;
}
int main()
{
    while(scanf("%s",  mes) != EOF){
        if(!strcmp(mes, "ENDOFINPUT")) break;
        ri = 0;
        while(scanf("%s", mes) != EOF){
            if(!strcmp(mes, "END")) break;
            int l = strlen(mes);
            for(int i = 0; i < l; i++)
                mes[i] = decode(mes[i]);
            strcpy(res[ri++], mes);
        }
        for(int k = 0; k < ri - 1; k++){
            printf("%s ", res[k]);
        }
        printf("%s\n", res[ri - 1]);
    }
    return 0;
}
