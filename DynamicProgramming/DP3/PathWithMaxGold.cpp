#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int r, int c, int gold, int& mxgold, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]){
        vis[r][c] = 1;
        gold += grid[r][c];

        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if( nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] != 0){

                dfs(nr, nc, gold, mxgold, n, m, grid, vis, delrow, delcol);
            }
        }
        mxgold = max(gold, mxgold);
        gold -= grid[r][c];
        vis[r][c] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int mxgold = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    int gold = 0;
                    dfs(i, j, gold, mxgold, n, m, grid, vis, delrow, delcol);
                    mxgold = max( gold, mxgold);
                }
            }
        }

        return mxgold;

    }
};