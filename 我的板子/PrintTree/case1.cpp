/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		queue<TreeNode* > q;
        vector<int> res;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(!root) continue;
            res.push_back(root->val);
            q.push(root->left);
            q.push(root->right);
        }
        return res;
    }
};