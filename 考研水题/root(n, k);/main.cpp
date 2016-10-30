/*
����root(N, k)�е�N�����ǿ��԰�N��������k�Ķ���ʽ��Ҳ����N = a0 + a1*k + a2*k^2 + �� + an* k^n��
������Ҫ���root���������������ʽ��ϵ���ͣ�Ҳ����a0 + a1 + a2 + ... + an���������ǿ���root(N^2, k)��
��ʱN^2 = (a0 + a1*k + a2*k^2 + �� + an* k^n)^2�����������ʽչ�����ϵ������(a0 + a1 + a2 + �� + an)^2��
�������պþ����ȶ�Nȡroot������ƽ���Ľ����ʵ���ϣ����Ǻ����׾��ܿ�����
����ʽ�ȳ˷���ȡϵ����(�ȳ���ȥ��k)����ȡϵ�����ٳ˷�(��ȥ��k�ٳ�)�������һ����(��Ϊ��û��k����Ӱ��ϵ�������ˣ�
Ҳ��Ӱ�����֮������)�����Ǻ������ǿ��Եõ����µĵ��ƹ�ʽ��
root(x, y, k) = root((root(x, y / 2, k))^2, 1, k)�� yΪż��
root(x, y, k) = root((root(x, y / 2, k))^2 * root(x, 1, k), 1, k)�� yΪ��1������
root(x, 1, k) = x % k + x / k % k + ...(����k�Ļ����ظ���root)
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