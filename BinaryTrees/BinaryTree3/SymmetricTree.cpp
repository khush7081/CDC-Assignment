#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q ==NULL) return false;
        
        if(p->val!=q->val) return false;
        bool leftans=helper(p->left,q->right);
        if(leftans==false) return false;
        bool rightans=helper(p->right, q->left);
        if(rightans==false) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        return helper(p,q);
    }
};