#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int count=1;
        if(n==0) count=0;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])==1) count++;
            else if(nums[i]==nums[i+1]) continue;
            else{
                maxi=max(count, maxi);
                count=1;
            }
        }
        maxi=max(count, maxi);
        return maxi;
        
    }
};