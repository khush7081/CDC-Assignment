#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void subsets(vector<int>&nums, int idx, vector<int>v, vector<vector<int>>& ans,  int n){
        if( idx == n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        subsets(nums, idx+1, v, ans, n);
        v.pop_back();
        while( idx + 1 < n && nums[idx] == nums[idx + 1]) idx++;
        
        subsets(nums, idx+1, v, ans,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        subsets(nums, 0, v, ans, n);
        return ans;
    }
};