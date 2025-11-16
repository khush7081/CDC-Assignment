#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(n==0){
            if(amount % coins[0] == 0 ) return amount/coins[0] ;
            return 1e9;
        }
        if(dp[n][amount]!= -1) return dp[n][amount];

        int pick=INT_MAX;
        if(coins[n]<=amount) pick=1+ f(n, amount-coins[n], coins, dp);
        int notpick= 0 + f(n-1,amount, coins, dp);

        return dp[n][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;

        // TABULATION

        // for(int t=0;t<=amount;t++){
        //     if(t%coins[0]==0) dp[0][t]= t/coins[0];
        //     else dp[0][t]=1e9;
        // }

        // for(int i=1;i<n;i++){
        //     for(int amt=0; amt<=amount;amt++){
        //         int pick=INT_MAX;
        //         if(coins[i]<=amt) pick = 1 + dp[i][amt-coins[i]];
        //         int notpick=0 + dp[i-1][amt];
        //         dp[i][amt]= min(pick, notpick);
        //     }
        // }
        // if(dp[n-1][amount]>=1e9) return -1;
        // return dp[n-1][amount];

        // SPACE OPTIMISATION
        
        // vector<int>prev(amount+1, 0) , curr(amount+1,0);

        // for(int t=0;t<=amount;t++){
        //     if(t%coins[0]==0) prev[t]= t/coins[0];
        //     else prev[t]=1e9;
        // }

        // for(int i=1;i<n;i++){
        //     for(int amt=0; amt<=amount;amt++){
        //         int pick=INT_MAX;
        //         if(coins[i]<=amt) pick = 1 + curr[amt-coins[i]];
        //         int notpick=0 + prev[amt];
        //         curr[amt]= min(pick, notpick);
        //     }
        //     prev=curr;
        // }
        // if(prev[amount]>=1e9) return -1;
        // return prev[amount];

    }
};