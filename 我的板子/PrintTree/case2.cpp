
//�����ӡ����������ڱȽϼ򵥵�
//�����Ͽε�ʱ����ʾ��

bool PrintTree(Node* root, int l){
	
	if(!root ) return false;
	PrintTree(root->right, l + 3);
	for(int i = 0; i < l; i++) printf(" ");
	printf("%c\n", root->val);
	PrintTree(root->left, l + 3);
	return true;
}

//�����ӡ
//���Ȼ���������
int GetDeep(Node* root){
	if(!root) return 0;
	int r, l;
	r = GetDeep(root->right);
	l = GetDeep(root->left);
	return max(r, l) + 1;
}

void PrintTree(Node* root, int deep){
	if(!root) return;
	queue<Node*> q1, q2;
	q1.push(root);
	int maxDeep = pow(2, deep); //�����
	int start = pow(2, deep - 1); //ÿ�㿪ʼ��ӡ�ĵط�
	while(deep){
		for(int i = 0; i < start; i ++) printf(" ");
		while(!q1.empty())
			q2.push(q1.top()), q1.pop();
		while(!q2.empty()){
			Node* r = q1.top();
			printf("%d", r->val);
			q1.push(r->left);
			q1.push(r->right);
			q2.pop();
			for(int i = 0; i < maxDeep; i ++) printf(" ");
		}
		maxDeep = pow(2, --deep);
		start = pow(2, deep - 1);
	}
}