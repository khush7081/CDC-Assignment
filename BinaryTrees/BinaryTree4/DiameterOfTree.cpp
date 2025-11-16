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
    void helper(TreeNode* root, int &maxDia){
        if(root==NULL) return ;
        int dia=levels(root->left)+levels(root->right);
        maxDia=max(maxDia, dia);
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;
        helper(root,maxDia);
        return maxDia;
    }
};