

void PostOrder(Node* root){
	stack<Node*> s;
	Node* cur;
	Node* pre;
	s.push(root);
	while(!s.empty()){
		cur = s.top();
		if((cur->lnode == NULL && cur->rnode == NULL) || 
		(!pre && (cur->lnode == pre || cur->rnode == pre))){
			cout<< cur->value << endl;
			s.pop();
			pre = cur;
		}else{
			if(cur->rnode) s.push(cur->rnode);
			if(cur->lnode) s.push(cur->lnode):
		}
	}
	
}