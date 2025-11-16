#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
         
        int ans = 0;
        for(int bit = 0; bit <= 31; bit++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] & (1 << bit)) count++;
            }
            if( count % 3 != 0) ans = ans | (1 << bit);
        }
        return ans;
        
    }
};