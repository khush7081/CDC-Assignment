#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f( string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + f(s1,s2, i-1, j-1,dp);

        return dp[i][j] = max( f(s1, s2, i-1, j,dp), f(s1, s2, i, j-1,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.length();
        int m=t2.length();
        //vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        //return f(t1, t2, n, m, dp);  

        // TABULATION

        // for(int i=0;i<=n;i++) dp[i][0] = 0 ;
        // for(int j=0;j<=m;j++) dp[0][j] = 0;

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(t1[i-1]==t2[j-1]) dp[i][j]= 1 + dp[i-1][j-1];
        //         else{
        //             dp[i][j]= max( dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m];

        // SPACE OPTIMISATION

        vector<int>prev(m+1,0), curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1]) curr[j]= 1 + prev[j-1];
                else{
                    curr[j]= max( prev[j], curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];

       
    }
};