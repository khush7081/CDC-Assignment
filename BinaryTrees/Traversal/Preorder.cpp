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
    vector<int>ans;
    void preorder(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
    
};