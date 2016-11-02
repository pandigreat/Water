

//当二叉数是搜索二叉树的时候

int solve(Node n1, Node n2, Node* t){
	int l = n1.value, r = n2.value;
	if(l > r) swap(l, r);
	while(true){
		if(t.value < l) t = t.right;
		else if(t.value > r) t = t.left;
		else if(t.value == l || t.value == r) return t.value;
	}
}

//