#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void f( vector< vector<int> >& ans, vector<int>& nums, vector<int>v, int idx, int target){
            if( target == 0){
                ans.push_back(v);
                return ;
            }
            for( int i = idx; i < nums.size(); i++){
                if( i > idx && nums[i] == nums[i-1]) continue;
                if( nums[i] > target) break;

                v.push_back(nums[i]);
                f(ans, nums, v, i + 1, target - nums[i]);
                v.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<int>v;
        vector< vector<int> >ans;
        f(ans, nums, v, 0, target);
        return ans;
    }
};