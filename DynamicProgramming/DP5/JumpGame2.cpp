#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int f(int idx, int n, vector<int>&nums, vector<int> &dp){
        if(idx==n) return 0;
        if(nums[idx]==0) return 1e8;
        if(dp[idx]!=-1) return dp[idx];
        int mini=INT_MAX;
        for(int i =1;i<=nums[idx]; i++){
            if(i+idx <= n){
                int jmp= 1 + f(idx+i, n, nums, dp);
                mini=min(mini, jmp);
            }
        }
        return  dp[idx] =mini;

    }
    int jump(vector<int>& nums) {
        int  n=nums.size();
        vector<int>dp(n,-1);
        return f(0, n-1, nums, dp);        
    }
};