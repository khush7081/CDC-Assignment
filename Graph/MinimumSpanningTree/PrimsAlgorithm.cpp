#include<iostream>
#include<vector>
#include<queue>
using namespace std;
   int spanningTree(int v, vector<vector<int>>& edges) {
        
        vector< pair<int,int>> adj[1];
        
        for( auto it : edges){
            adj[it[0]].push_back({ it[1], it[2]});
            adj[it[1]].push_back({ it[0], it[2]});
        }
        
        vector<int>vis(v, 0);
        
        int sum = 0;
        
        priority_queue< pair< int, int>, vector< pair<int, int>>, greater< pair<int,int>> > pq;
        pq.push({ 0, 0});
        
        while( pq.size()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if( vis[node] == 1) continue;
            // add it to the MST
            sum += cost;
            vis[node] = 1;
            
            for( auto it : adj[node]){
                int adjnode = it.first;
                int edw = it.second;
                
                if( vis[adjnode] == 0){
                    pq.push( { edw, adjnode});
                }
            }
        }
        return sum;
        
    }