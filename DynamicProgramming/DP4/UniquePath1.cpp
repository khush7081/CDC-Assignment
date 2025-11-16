#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int u=f(i-1,j,dp);
        int l=f(i,j-1,dp);
        return dp[i][j]=u+l;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);

        // TABULATION
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int u=0,l=0;
                    if(i>0) u=dp[i-1][j];
                    if(j>0) l=dp[i][j-1];
                    dp[i][j]=u+l;
                }
            }
        }
        return dp[m-1][n-1];
    }
};