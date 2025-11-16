#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

class Solution {
  public:
    void f( Node* root, vector<int>& ans){
        unordered_map< int, int> mp;    // < level, value>
        queue< pair<Node* , int>> q;
        q.push( {root, 0});
        
        int minlevel = INT_MAX;
        int maxlevel = INT_MIN;
        
        while(q.size()){
            Node* temp = q.front().first;
            int level = q.front().second;
            
            minlevel = min( minlevel, level);
            maxlevel = max( maxlevel, level);
            
            q.pop();
            
            if( mp.find(level) == mp.end()) mp[level] = temp->val;
            
            if( temp ->left){
                q.push( { temp->left, level -1});
            }
            if( temp -> right){
                q.push( { temp->right, level + 1});
            }
        }
        
        for(int i = minlevel; i <= maxlevel; i++){
            ans.push_back(mp[i]);
        }
    
    }
    vector<int> topView(Node *root) {
        vector<int>ans;
        f(root, ans);
        return ans;
    
    }
};