#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int u= grid[i][j] + f(i-1,j,grid,dp);
        int l= grid[i][j] + f(i,j-1,grid,dp);
        return dp[i][j]=min(u,l);   
    } 
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        //return f(m-1,n-1,grid,dp);

        // TABULATION

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0) dp[i][j]=grid[i][j];
        //         else{
        //             int u=grid[i][j], l=grid[i][j];
        //             if(i>0) u+=dp[i-1][j];
        //             else u+=1e9;
        //             if(j>0) l+=dp[i][j-1];
        //             else l+=1e9;
        //             dp[i][j]=min(u,l);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // SPACE OPTIMISATION

        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int u=grid[i][j], l=grid[i][j];
                    if(i>0) u+=prev[j];
                    else u+=1e9;
                    if(j>0) l+=curr[j-1];
                    else l+=1e9;
                    curr[j]= min(u,l);
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};