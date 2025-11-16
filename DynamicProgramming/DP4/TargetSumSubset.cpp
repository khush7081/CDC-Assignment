#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int n, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
       }
       if(dp[n][target] != -1) return dp[n][target];
       int pick=0;
       if(nums[n]<=target) pick=f(n-1, target-nums[n], nums, dp);
       int notpick= f(n-1,target, nums, dp);
       return dp[n][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int e:nums) sum+=e;
        if(sum-target <0 || (sum-target)%2!=0) return 0;
        target=(sum-target)/2;
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return f(n-1, target, nums, dp);
        
    }
};