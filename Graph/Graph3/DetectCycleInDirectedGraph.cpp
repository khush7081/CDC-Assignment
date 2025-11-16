#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis){
      vis[node] = 1;
      pathvis[node] = 1;
      
      for(auto it : adj[node]){
          if(vis[it] == 0){
              if(dfs(it, adj, vis, pathvis)) return true;
          }
          else if(pathvis[it] == 1) return true;
      }
      
      pathvis[node] = 0;
      return false;
  }
    bool isCyclic(int v, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[v];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(v,0);
        vector<int>pathvis(v,0);
        
        for(int i = 0; i < v; i++){
            if( vis[i] == 0){
                if(dfs(i, adj, vis, pathvis)) return true;
            }
        }
        return false;
    }
};