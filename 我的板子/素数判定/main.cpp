const int Max = 32000;
/**
*Max取这么多是因为，N=10^9，取平方根的话为32000
*
*/
void setPrime(){ ///素数判定法
    v[0] = v[1] = true;
    for(int i = 2; i < Max; i++){
        for(int j = i << 1; !v[i] && j < Max; j += i) v[j] = true;
    }
    for(int i = 0; i < Max; i++)
        if(!v[i]) prime.push_back(i);
}