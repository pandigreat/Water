typedef vector<int> vec;
typedef vector<vec> mat;
#define Max 10010

mat mul(mat a, mat b){
	mat c (a.size(), vec(a.size()));
	for(int i = 0; i < a.size(); i++)
		for(int k = 0; k < b[0].size(); k++)
			for(int j = 0; j < b.size(); j++)
				c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % Max;
	return c;
}

mat solve(mat a, int n){
	mat b(a,size(), vec(a.size()));
	for(int i = 0; i < a.size(); i++)
		b[i][i] = 1;
	while(n){
		if(n & 0x1 == 1)
			b = mul(b, a);
		a = mul(a, a);
		n >>= 1;
	}
	return b;
}