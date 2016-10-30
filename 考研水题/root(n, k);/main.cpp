/*
对于root(N, k)中的N，我们可以把N看作关于k的多项式，也就是N = a0 + a1*k + a2*k^2 + … + an* k^n，
而我们要求的root函数就是这个多项式的系数和，也就是a0 + a1 + a2 + ... + an。下面我们考虑root(N^2, k)。
此时N^2 = (a0 + a1*k + a2*k^2 + … + an* k^n)^2，而这个多项式展开后的系数和是(a0 + a1 + a2 + … + an)^2，
这个结果刚好就是先对N取root函数再平方的结果。实际上，我们很容易就能看出，
多项式先乘方再取系数和(先乘再去掉k)与先取系数和再乘方(先去掉k再乘)，结果是一样的(因为有没有k并不影响系数间的相乘，
也不影响相乘之后的求和)，于是乎，我们可以得到以下的递推公式：
root(x, y, k) = root((root(x, y / 2, k))^2, 1, k)， y为偶数
root(x, y, k) = root((root(x, y / 2, k))^2 * root(x, 1, k), 1, k)， y为非1的奇数
root(x, 1, k) = x % k + x / k % k + ...(大于k的话再重复求root)
*/

int root(int x, int y, int k){
	if(y == 1){
		if(x < k) return x;
		int res = 0;
		while(x >= k){
			res = 0;
			while(x > 0){
				res += x % k;
				x /= k;
			}
			x = res; 
		}
		return res;
	}else{
		int res = root(x, y / 2, k);
		res *= res;
		if(y & 0x1 == 1) res *= root(x, 1, k);
		return root(res, 1, k);
	}
}