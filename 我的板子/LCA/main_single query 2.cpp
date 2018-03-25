
int getPre(int x){
	return x == pre[x]? x: getPre(pre[x]);
}

void union_set(int x, int y){
    x = getPre(x);
    y = getPre(y);
    if(x != y) pre[x] = y;
}

 
#include <cstdio>
#include <cstring>
const int N = 510;
int pre[N];

///�Ѿ�������һ�Σ����Pre����rank�ĸ���
node* getLCA(node* root, node* node1, node* node2)    
{    
    if(root == null)    
        return null;    
    if(root== node1 || root==node2)    
        return root;    
  
    node* left = getLCA(root->left, node1, node2);    
    node* right = getLCA(root->right, node1, node2);    
      
    // node1 �� node2 ���������ȹ�ϵ  
    if(left != null && right != null)    
        return root;   
    // node1 �� node2 ����һ������һ��������  
    else if(left != null)    
        return left;    
    else if (right != null)    
        return right;    
    else     
        return null;    
}  
