#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void dfs( int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && vis[nr][nc] == 0){
                dfs(nr, nc, n, m, grid, vis, delrow, delcol);   
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int m = grid[0].size();
        queue< pair<int,int> >q;
        for(int i = 0; i < n; i++){
            if( grid[i][0] == 0) q.push({i, 0});
            if( grid[i][m-1] == 0) q.push( {i, m-1});
        }
         for(int j = 0; j < m; j++){
            if( grid[0][j] == 0) q.push({0, j});
            if( grid[n-1][j] == 0) q.push( {n-1, j});
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(q.size()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            grid[r][c] = 1;

            for(int i = 0; i < 4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                    q.push({nr, nc});
                }
            }
        }

        vector<vector<int>> vis(n, vector<int>(m,0));

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( grid[i][j] == 0 && vis[i][j] == 0){
                    count++;
                    dfs(i, j, n, m, grid, vis, delrow, delcol);
                }
            }
        }

        return count;
        
    }
};