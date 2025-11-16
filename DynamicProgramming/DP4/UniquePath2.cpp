#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   int f(int i,int j,vector<vector<int>>&Grid,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && Grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int l=f(i,j-1,Grid,dp);
        int u=f(i-1,j,Grid,dp);
        return dp[i][j]=u+l;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        //return f(0,0,m,n,Grid,dp);
        //return f(m-1,n-1,Grid,dp);


        // TABULATION

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(Grid[i][j]==1) dp[i][j]=0;
        //         else if(i==0 && j==0) dp[i][j]=1;
        //         else{
        //             int l=0,u=0;
        //             if(j>0) l=dp[i][j-1];
        //             if(i>0) u=dp[i-1][j];
        //             dp[i][j]=l+u;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(Grid[i][j]==1) curr[j]=0;
                else if(i==0 && j==0) curr[j]=1;
                else{
                    int u=0,l=0;
                    if(j>0) l=curr[j-1];
                    if(i>0) u=prev[j];
                    curr[j]=u+l;
                }
            }
            prev=curr;
        }
        return prev[n-1];
       
    }
};