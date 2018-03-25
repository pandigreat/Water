
int getPre(int x){
	return x == pre[x]? x: getPre(pre[x]);
}

void union_set(int x, int y){
    x = getPre(x);
    y = getPre(y);
    if(x != y) pre[x] = y;
}


/**

就是一个树，pre数组就是记录某个点的父节点，当pre[i] = i的时候
就说明这个点就是他所在树的root
并查集就是将两个树进行合并的


*/


/**路径压缩的版本如下
*路径压缩之后平均的时间复杂度是 O(a(n)), a(n)是阿克曼函数，	O(log(n))还快
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
是否有公共的祖先
*/
bool IsTheFamily(int x, int y){
	return getPre(x) == getPre(y);	
}





