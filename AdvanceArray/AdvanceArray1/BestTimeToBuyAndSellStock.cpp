#include<iostream>
#include<vector>

using namespace std;
 int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxp = 0;
        for(int i = 1; i<n; i++){
            if( nums[i] > mini){
                maxp = max( maxp, nums[i]-mini);
            }
            mini= min( mini, nums[i]);
        }
        return maxp;
        
    }