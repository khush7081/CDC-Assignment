#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int n, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(n==0){
            if(amount % coins[0]==0) return 1;
            else return 0;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];

        int pick=0;
        if(coins[n]<=amount) pick=f(n, amount-coins[n], coins, dp);
        int notpick= f(n-1, amount, coins, dp);
        return dp[n][amount] = pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins,dp);

        // TABULATION
        
        // for(int t=0;t<=amount;t++){
        //     if(t % coins[0]==0) dp[0][t]=1;
        //     else dp[0][t]=0;
        // }
        //for(int i=0;i<n;i++) dp[i][0]=1;
        // for(int i=1;i<n;i++){
        //     for(int amt=0;amt<=amount;amt++){
        //         int pick=0;
        //         if(coins[i]<=amt) pick=dp[i][amt-coins[i]];
        //         int notpick= dp[i-1][amt];
        //         dp[i][amt] = pick + notpick;
        //     }
        // }
        // return dp[n-1][amount];
    }
};