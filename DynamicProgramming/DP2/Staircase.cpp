#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Memoization

    // int ways(int n, vector<int>&dp){
    //     if(n==1) return 1;
    //     if(n==2) return 2;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=ways(n-1,dp)+ways(n-2,dp);
    // }

    int climbStairs(int n) {

        // vector<int>dp(n+1,-1);
        // return ways(n,dp);
        
        if(n==1) return 1;
        int a=1;
        int b=2;
        for(int i=3;i<=n;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;

    }
};