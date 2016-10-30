#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include <iomanip>
#include <set>
#define inf 2000000000
#define ll unsigned long long
/**序树，也称为二叉查找树。可以是一颗空树，也可以是一颗具有如下特性的非空二叉树：


        1. 若左子树非空，则左子树上所有节点关键字值均不大于根节点的关键字值；
        2. 若右子树非空，则右子树上所有节点关键字值均不小于根节点的关键字值；
        3. 左、右子树本身也是一颗二叉排序树。


　　现在给你N个关键字值各不相同的节点，要求你按顺序插入一个初始为空树的二叉排序树中，每次插入后成功后，求相应的父亲节点的关键字值，如果没有父亲节点，则输出-1。

样例输入：

    5
    2 5 1 3 4

样例输出：

    -1
    2
    2
    5
    3

 
*
*/

using namespace std;
typedef struct Node{
    int val;
    bool l, r;
    Node* right;
    Node* left;
    Node(): val(-1), l(false), r(false), left(NULL), right(NULL){}
}Node;
int a, b, l;
int n;

void de(Node* &root){
    if((root)){
        de((root)->left);
        de(root->right);
        free(root);
    }
}

Node* create(){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
}

int main(){
    while(~scanf("%d", &n)){
        Node* r = create();
        for(int i = 0; i < n; i++){
            Node *root = r;
            scanf("%d", &a);
            int pre = -1;
            if(!i){
                root->val = a;
            }
            while(i){
                pre = root->val;
                if(a > root->val){
                    if(root->right != NULL){
                        root = root->right;
                    }else{
                        root->right = create();
                        root->right->val = a;
                        break;
                    }
                }else{
                    if(root->left != NULL) root = root->left;
                    else{
                        root->left = create();
                        root->left->val = a;
                        break;
                    }
                }
            }
            printf("%d\n", pre);
        }
    }
    return 0;
}

