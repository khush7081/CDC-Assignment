#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {

        unordered_map < int, pair<int,int>> mp;
        unordered_set< int> s;

        int n = des.size();

        for( int i = 0;  i < n; i++){
            int parent = des[i][0];
            int child = des[i][1];
            s.insert(child);
            if( mp.find(parent) == mp.end()){
                if( des[i][2] == 1) mp[parent] = {child, 0};
                else mp[parent] = {0, child};
            }
            else{
                if( des[i][2] == 1) mp[parent].first = child;
                else mp[parent].second = child;
            }
        }

        // finding the root 

        TreeNode* root;
       

        for( auto it : mp){
            int par = it.first;
            if( s.find(par) == s.end()){
                root = new TreeNode(par);
                break;
            }
        }

        queue< TreeNode* >q;
        q.push(root);

        while(q.size()){
            TreeNode* temp = q.front();
            q.pop();
            int parent = temp->val;
            TreeNode* lc;
            TreeNode* rc;
            if( mp[parent].first != 0) lc = new TreeNode( mp[parent].first);
            else lc = NULL;

            if( mp[parent].second != 0) rc = new TreeNode( mp[parent].second);
            else rc = NULL;

            temp->left = lc;
            temp->right = rc;

            if( lc) q.push(lc);
            if( rc) q.push(rc); 
        }

        return root;
    
    }
};