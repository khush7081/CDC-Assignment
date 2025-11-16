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
    int sumofLeft( TreeNode* root){
        if( root == NULL) return 0;
        int s = 0;
        if( root->left) if( root->left->left == NULL && root->left->right == NULL){
            s = root->left->val;
        }
        return s + sumofLeft( root->left) + sumofLeft( root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumofLeft(root);
    }
};