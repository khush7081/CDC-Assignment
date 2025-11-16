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
    
    void inorder(TreeNode* root){
        TreeNode* curr=root;
        while(curr){
            if(curr->left){    // find predecessor
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr) pred=pred->right;
                if(pred->right==NULL){  //link;
                    pred->right=curr;
                    curr=curr->left;
                }
                else if(pred->right==curr){   //unlink
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            }

        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};