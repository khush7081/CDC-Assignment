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
 vector<int> ans;
    void postorder(TreeNode* root){
        if(root==NULL) return ;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
   
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
        
    }
};