#include<iostream>
#include<vector>
using namespace std;
vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        
        vector<int>dist(v, 1e8);
        dist[src] = 0;
        
        for(int i = 0 ; i < v - 1; i++){
            
            for( auto it : edges){
                int u = it[0];
                int v = it[1];
                int d = it[2];
                
                if( dist[u] != 1e8 && dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d; 
                }
            }
        }
        
        // LAST ITERATION TO CHECK NEGATIVE CYCLE
        
        for( auto it : edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
                
            if( dist[u] != 1e8 && dist[u] + d < dist[v]){
                    return {-1};
            }
        }
        
        return dist;
        
    }