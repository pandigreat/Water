

void InOrder(Node* root){
	stack<Node*> s;
	Node* p = root;
	while(!p || !s.empty()){
		while(!p){
			
			s.push(p);
			p = p->lnode;
		}
		if(!s.empty()){
			p = s.top();
			cout<< p->value << endl;
			s.pop();
			p = p->rnode;
		}
	}
	
}