#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int f( int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if( i == n || j == m) return 0;
        if( j == m-1) return mat[i][j];
     
        if( dp[i][j] != -1) return dp[i][j];
        int upright = 0;
        int right = 0;
        int downright = 0;
            
        if( i - 1 >= 0 && j + 1< m) upright += f(i - 1, j + 1, n, m, mat, dp);
        if( j + 1 < m) right += f(i, j + 1, n, m, mat, dp);
        if( i + 1 < n && j + 1 < m) downright += f( i + 1, j + 1, n ,m ,mat, dp);
        
        return dp[i][j] = mat[i][j] + max( upright, max(right, downright));
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int mxgold = 0;
        
        for(int i = 0; i < n; i++){
            mxgold = max(mxgold, f(i, 0, n, m, mat, dp));
        }
        return mxgold;
    }
};