bool witness(int a,int n)
{
    int t,d,x;
    d=1;
    int i=ceil(log(n-1.0)/log(2.0)) - 1;
    for(;i>=0;i--)
    {
        x=d;  d=(d*d)%n;
        if(d==1 && x!=1 && x!=n-1) return true;
        if( ((n-1) & (1<<i)) > 0)
            d=(d*a)%n;
    }
    return d==1? false : true;
}
bool miller_rabin(int n)
{
    int s[]={2,7,61};
    if(n==2)    return true;
    if(n==1 || ((n&1)==0))    return false;
    for(int i=0;i<3;i++)
        if(witness(s[i], n))    return false;
    return true;
}
