const int Max = 32000;
/**
*Maxȡ��ô������Ϊ��N=10^9��ȡƽ�����Ļ�Ϊ32000
*
*/
void setPrime(){ ///�����ж���
    v[0] = v[1] = true;
    for(int i = 2; i < Max; i++){
        for(int j = i << 1; !v[i] && j < Max; j += i) v[j] = true;
    }
    for(int i = 0; i < Max; i++)
        if(!v[i]) prime.push_back(i);
}