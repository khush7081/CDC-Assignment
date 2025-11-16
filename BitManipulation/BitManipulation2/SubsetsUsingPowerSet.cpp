#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   
    void powerset(vector<vector<int>>&ans, int n, vector<int>& nums){
        int size = 1<<n;
        for(int num = 0; num <size; num++){
            vector<int>v;
            for(int i = 0; i < n; i++){
                if( num & (1 << i)) v.push_back(nums[i]);
            }
            ans.push_back(v);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> finalans;
        int n = nums.size();
        powerset(finalans, n, nums);
        return finalans;
    }
};