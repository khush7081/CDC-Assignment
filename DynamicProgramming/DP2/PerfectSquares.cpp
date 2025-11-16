#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int idx, int n, vector<int>&nums, vector<vector<int>>& dp){
        if(n == 0) return 0;
        if(idx >= nums.size()) return 1e9;
        if( nums[idx] > n) return 1e9;

        if(dp[idx][n] != -1) return dp[idx][n];
        int p = 1e9;
        if( nums[idx] <= n) p = 1 + f(idx, n - nums[idx], nums, dp);
        int np = 0 + f(idx + 1, n, nums, dp);
        return dp[idx][n] = min(p, np);
    }
    int numSquares(int n) {

        vector<int>nums;
        for(int i = 1; i <= n; i++){
            if( i*i > n) break;
            nums.push_back(i*i);
        }
        int m = nums.size();

        // vector<vector<int>>dp(m, vector<int>(n+1, -1));
        // return f(0, n, nums, dp);

        // TABULATION

        // vector<vector<int>>dp(m + 1, vector<int>(n+1, 0));
        // for(int j = 1; j <= n; j++){
        //     dp[m][j] = 1e9;
        // }
        // for(int idx = m-1; idx >= 0; idx--){
        //     for(int j = 1; j <= n; j++){
        //        int p = 1e9;
        //        if( nums[idx] <= j) p = 1 + dp[idx][j - nums[idx]];
        //        int np = 0 + dp[idx+1][j];
        //        dp[idx][j] = min(p,np);
        //     }
        // }
        // return dp[0][n];

        vector<int>front(n+1), curr(n+1);
        for(int j = 1; j <= n; j++){
            front[j] = 1e9;
        }
        for(int idx = m-1; idx >= 0; idx--){
            for(int j = 1; j <= n; j++){
               int p = 1e9;
               if( nums[idx] <= j) p = 1 + curr[j - nums[idx]];
               int np = 0 + front[j];
               curr[j] = min(p,np);
            }
            front = curr;
        }
        return front[n];
        
    }
};