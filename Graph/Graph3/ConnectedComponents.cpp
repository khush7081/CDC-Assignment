#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   void dfs( int node, vector<vector<int>>& adj, vector<int>& vis){
       vis[node] = 1;   
       for( auto it : adj[node]){
           if(vis[it] == 0){
               dfs( it, adj, vis);
           }
       }
   }
    int countComponents(int n, vector<vector<int>>& edges) {
       
        vector<vector<int>>adj(n, vector<int>());

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 0;
        
        vector<int>vis(n,0);

        for(int i = 0; i < n; i++){
            if( !vis[i]){
                count++;
                dfs( i, adj, vis);
            }
        }
        return count;


    }
};
