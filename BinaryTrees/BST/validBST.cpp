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
   
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
       
        vector<int>ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]) return false;
        }
        return true;
    
    }
};