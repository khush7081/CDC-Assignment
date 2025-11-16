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
    int levels( TreeNode* root){
        if( root == NULL) return 0;
        return 1 + max( levels(root->left), levels(root->right));
    }
    int maxDepth(TreeNode* root) {
        return levels(root);
    }
};