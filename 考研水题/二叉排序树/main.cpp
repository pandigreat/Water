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
/**������Ҳ��Ϊ�����������������һ�ſ�����Ҳ������һ�ž����������Եķǿն�������


        1. ���������ǿգ��������������нڵ�ؼ���ֵ�������ڸ��ڵ�Ĺؼ���ֵ��
        2. ���������ǿգ��������������нڵ�ؼ���ֵ����С�ڸ��ڵ�Ĺؼ���ֵ��
        3. ������������Ҳ��һ�Ŷ�����������


�������ڸ���N���ؼ���ֵ������ͬ�Ľڵ㣬Ҫ���㰴˳�����һ����ʼΪ�����Ķ����������У�ÿ�β����ɹ�������Ӧ�ĸ��׽ڵ�Ĺؼ���ֵ�����û�и��׽ڵ㣬�����-1��

�������룺

    5
    2 5 1 3 4

���������

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

