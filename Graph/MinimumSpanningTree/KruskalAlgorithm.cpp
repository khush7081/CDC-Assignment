#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet( int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for( int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar( int node){
        if( node == parent[node]) return node;
        return parent[node] = findUPar( parent[node]);            // PATH COMPRESSION
    }

    void UnionByRank( int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if( ulp_u == ulp_v) return;

        if( rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if( rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};
class Solution {
  public:
    int spanningTree(int v, vector<vector<int>>& edges) {
        
        vector< pair<int, pair<int,int>>> adj;
        
        for( auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj.push_back( {wt, { u, v}});
        }
        
        sort( adj.begin(), adj.end());
        
        DisjointSet ds(v);
        
        int sum = 0;
        
        for( auto it : adj){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if( ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;
                ds.UnionByRank( u, v);
            }
        }
        
        return sum;
        
    }
};