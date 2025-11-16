#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    
    void combination(vector<vector<int>>&ans,vector<int>&nums,int target,vector<int>v,int idx){   
        if(idx == nums.size()){
            if( target == 0) {
                ans.push_back(v);
            }
            return;
        }

        if( nums[idx] <= target){
            v.push_back(nums[idx]);
            combination(ans, nums, target - nums[idx], v, idx);
            v.pop_back();
        }
        combination(ans, nums, target, v, idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>v;
        combination(ans,candidates,target,v,0);
        return ans;

    }
};