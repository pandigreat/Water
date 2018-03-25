
int getPre(int x){
	return x == pre[x]? x: getPre(pre[x]);
}

void union_set(int x, int y){
    x = getPre(x);
    y = getPre(y);
    if(x != y) pre[x] = y;
}


/**

����һ������pre������Ǽ�¼ĳ����ĸ��ڵ㣬��pre[i] = i��ʱ��
��˵��������������������root
���鼯���ǽ����������кϲ���


*/


/**·��ѹ���İ汾����
*·��ѹ��֮��ƽ����ʱ�临�Ӷ��� O(a(n)), a(n)�ǰ�����������	O(log(n))����
*/

int getPre(int x){
	int r = x;
	while(r != pre[r])
		r = pre[r];
	int i = x, j;
	while(i != r){
		
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void union_set(int x, int y){
	x = getPre(x);
	y = getPre(y);
	if(x != y)
		pre[x] = y;
}

/**
�Ƿ��й���������
*/
bool IsTheFamily(int x, int y){
	return getPre(x) == getPre(y);	
}





