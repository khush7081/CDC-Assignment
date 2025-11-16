#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue <pair<int,int> >q;
        q.push( {row, col});
        int n = grid.size();
        int m = grid[0].size();
        while( q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if( r + 1 < n && vis[r + 1][c] == 0 && grid[r+1][c] == '1'){
                vis[r + 1][c] = 1;
                q.push( {r + 1, c} );
            }
            if( r - 1 >= 0 && vis[r - 1][c] == 0 && grid[r-1][c] == '1'){
                vis[r - 1][c] = 1;
                q.push( {r - 1, c} );
            }
            if( c + 1 < m && vis[r][c + 1] == 0 && grid[r][c+1] == '1'){
                vis[r][c + 1] = 1;
                q.push( {r, c + 1} );
            }
            if( c - 1 >= 0 && vis[r][c - 1] == 0 && grid[r][c-1] == '1'){
                vis[r][c - 1] = 1;
                q.push( { r, c - 1} );
            }
            
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    bfs( i, j, grid, vis);
                }
            }
        }
        return count;
    }
};