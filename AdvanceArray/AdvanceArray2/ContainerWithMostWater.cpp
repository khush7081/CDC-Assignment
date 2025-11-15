#include<iostream>
#include<vector>
using namespace std;
 int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxw = INT_MIN;

        int i = 0;
        int j = n-1;
        while ( i <= j){
            int water = ( j - i) * min(nums[i], nums[j]);
            maxw = max( maxw, water);
            if( nums[i] < nums[j]) i++;
            else j--;
        }
        
        return maxw;
    }