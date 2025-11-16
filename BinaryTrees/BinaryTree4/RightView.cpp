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
        return 1+max(levels(root->left), levels(root->right));
    }
    void printnth(TreeNode* root,vector<int>&ans,int level,int n){
        if(root==NULL) return;
        if(level==n) ans[level]=root->val;
        printnth(root->left,ans,level+1,n);
        printnth(root->right,ans,level+1,n);
    }
    vector<int> rightSideView(TreeNode* root) {
        int l=levels(root);
        vector<int>ans(l);
        for(int i=0;i<l;i++){
            printnth(root,ans,0,i);
        }
        return ans;
    }
};