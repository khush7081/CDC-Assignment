#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int findSubarray(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        int presum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;

        for(int i = 0; i < n;i++){
            presum += nums[i];
            int target = presum - 0;
            ans += mp[target];
            mp[presum]++;
        }

        return ans;
    }
};