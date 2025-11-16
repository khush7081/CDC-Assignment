#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        
        int e = edges.size();

        vector< pair<int, int> > adj[10];
        
        for(int i = 0 ; i < e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            
            adj[u].push_back( {v, d});
            adj[v].push_back( {u, d});
        }
        
        priority_queue< pair<int,int>, vector< pair<int,int>>,  greater< pair<int,int>> > pq;
        vector<int> dist(n, 1e9);
        
        pq.push( { 0, src});
        dist[src] = 0;
        
        while( pq.size()){
            int currdis = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            
            for( auto node : adj[curr]){
                int v = node.first;
                int d = node.second;
                
                if( currdis + d < dist[v]){
                    dist[v] = currdis + d;
                    pq.push( { dist[v], v});
                }

            }
        }
        return dist;
        
    }

   