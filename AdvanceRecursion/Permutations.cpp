#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    
    void f( vector<int> nums, int idx, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap( nums[i], nums[idx]);
            f(nums, idx + 1, ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        f(nums, 0, ans);
        return ans;
    }
};