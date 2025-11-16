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
    bool psum(TreeNode* root, int target){
        if(root==NULL) return false;
        target-=root->val;
        if(root->left==NULL && root->right==NULL && target==0) return true;
        bool l=psum(root->left,target);
        if(l==true) return true;
        bool r=psum(root->right,target);
        if(r==true) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int target) {
        return psum(root,target);
    }
};