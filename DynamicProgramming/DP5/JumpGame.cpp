#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool f(int idx, int n, vector<int>&nums, vector<int> &dp){
        if(idx==n){
            return true;
        }
        if(idx!=n && nums[idx]==0) return false;
        
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(idx+i <= n){
                bool flag=f(idx+i, n, nums,dp);
                if(flag==true) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(0, n-1, nums, dp);
    }
};