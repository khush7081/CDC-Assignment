#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs( int node, int n, vector<vector<int>>& graph, vector<int>& v, vector<vector<int>>& ans, vector<int>& vis){
        if( node == n-1){
            v.push_back(node);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        vis[node] = 1;
        v.push_back(node);

        for(auto it : graph[node]){
            if(vis[it] == 0){
                dfs(it, n, graph, v, ans, vis);
            }
        }
        vis[node] = 0;
        v.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>vis(n, 0);
        dfs(0, n, graph, v, ans, vis);
        return ans;
    }
};