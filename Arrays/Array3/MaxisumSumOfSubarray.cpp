#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
        }
        return maxi;
        
    }