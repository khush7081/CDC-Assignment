#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    
    vector<vector<int>> printGraph(int v, vector<pair<int, int>>& edges) {
       
        vector<vector<int>>adj(v);
        
        for(auto it : edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        return adj;
    }
};