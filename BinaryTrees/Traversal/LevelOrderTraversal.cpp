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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
   
    void lorder(TreeNode* root,int level, vector<vector<int>>&ans){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        lorder(root->left,level+1,ans);
        lorder(root->right,level+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int n=levels(root);
       
        for(int i=1;i<=n;i++){
            vector<int>v;
            ans.push_back(v);
        }
        lorder(root,0,ans);
        return ans;
            
    }
};