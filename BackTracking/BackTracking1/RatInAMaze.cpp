#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    void f(int r, int c, int n, string s, vector<vector<int>>& maze, vector<vector<int>>& vis, vector<string>& ans, int delrow[], int delcol[], char str[]){
        if( maze[r][c] == 0) return;
        if( r == n-1 && c == n-1){
            if( maze[r][c] == 0) return;
            ans.push_back(s);
            return ;
        }
        for(int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if( nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0 && maze[nr][nc] == 1){
                vis[r][c] = 1;
                f( nr, nc, n, s + str[i], maze, vis, ans, delrow, delcol, str);
                vis[r][c] = 0;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<int>>vis(n, vector<int>(n,0));
        vector<string>ans;
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        char str[] = {'D', 'L', 'R', 'U'};
        string s = "";
        f(0, 0, n, s, maze, vis, ans, delrow, delcol, str);
        return ans;
    
    }
};