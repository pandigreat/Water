bool lca(Node *root, int va, int vb, Node *&result, Node* parent)
{
    // left/right 左/右子树是否含有要判断的两节点之一 
    bool left = false, right = false;
    if (!result && root->left) left = lca(root->left,va,vb,result,root);
    if (!result && root->right) right = lca(root->right,va,vb,result,root);

    // mid 当前节点是否是要判断的两节点之一 
    bool mid = false;
    if (root->data == va || root->data == vb) mid=true;
    if (!result && int(left + right + mid) == 2) {
        if (mid) result = parent;
        else result = root;
    }
    return left | mid | right ;
}

Node *query(Node *root,int va, int vb)
{
    if (root == NULL) return NULL;
    Node *result = NULL;
    lca(root, va, vb,result, NULL);
    return result;
}


/// 
node *getLCA(node *root, node *node1, node *node2)
{
    if(root == NULL) return NULL;
    if(root == node1 || root == node2) return root;
    node *left = getLCA(root->left, node1, node2);
    node *right = getLCA(root->right, node1, node2);
    if(left != NULL && right != NULL) return root;
    else if(left != NULL) return left;
    else if(right != NULL) return right;
    else return NULL;
}