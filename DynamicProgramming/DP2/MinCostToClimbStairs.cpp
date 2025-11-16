#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int idx, int n, vector<int>& cost, vector<int>& dp){
        if(idx == n) return 0;
        if( idx == n-1) return cost[idx];

        if(idx == -1) return min(f(idx + 1, n, cost, dp), f(idx + 2, n, cost, dp));
        if(dp[idx] != -1) return dp[idx];
        int p = 1e9;;
        if( idx + 1 <= n){
            p = cost[idx] + f(idx + 1, n, cost, dp);
        }
        int np = 1e9;
        if( idx + 2 <= n){
            np = cost[idx] + f(idx + 2, n, cost, dp);
        } 
        return dp[idx] = min(p, np);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int>dp(n, -1);
        // return f(-1, n, cost, dp);

        vector<int>dp(n+1, 0);
        dp[n-1] = cost[n-1];

        for(int idx = n-2; idx >= 0; idx--){    
            int one = 1e9;
            if( idx + 1 <= n) one = cost[idx] + dp[idx + 1];
            int two = 1e9;
            if( idx + 2 <= n) two = cost[idx] + dp[idx + 2];

            dp[idx] = min(one , two);
        }
        return min(dp[0], dp[1]);
    }
};