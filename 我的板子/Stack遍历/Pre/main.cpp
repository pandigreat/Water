


void PreOrder(Node* root){
	Node* p = root;
	stack<Node*> s;
	while(p != NULL || !s.empty()){
		
		while(p != NULL){
			cout << p->value << endl;
			s.push(p);
			p = p->lnode;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			p = p->rnode;
		}
	}
}