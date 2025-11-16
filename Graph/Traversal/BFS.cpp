#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<int>vis(n,0);
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        
        vector<int>ans;
        
        while(q.size()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if( vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
            
        }
        return ans;
    }
};