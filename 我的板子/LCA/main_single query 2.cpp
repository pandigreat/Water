
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

///已经遍历过一次，完成Pre还有rank的更新
node* getLCA(node* root, node* node1, node* node2)    
{    
    if(root == null)    
        return null;    
    if(root== node1 || root==node2)    
        return root;    
  
    node* left = getLCA(root->left, node1, node2);    
    node* right = getLCA(root->right, node1, node2);    
      
    // node1 和 node2 不存在祖先关系  
    if(left != null && right != null)    
        return root;   
    // node1 和 node2 其中一个是另一个的祖先  
    else if(left != null)    
        return left;    
    else if (right != null)    
        return right;    
    else     
        return null;    
}  
