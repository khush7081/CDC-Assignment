#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        if( src == dst) return true;
        vector<int> adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n,0);
        vis[src] = 1;

        queue<int>q;
        q.push(src);

        while(q.size()){
            int node = q.front();
            q.pop();
            if( node == dst) return true;
        
            for( auto it : adj[node]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                    if( it == dst) return true;
                }
            }
        }
        return false;
    }
};