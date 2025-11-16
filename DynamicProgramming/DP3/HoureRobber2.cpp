#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int money(vector<int>&nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;

            int curr=max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>a, b;
        if(n==1) return nums[0];
        // exclude last
        for(int i=0;i<n-1;i++) a.push_back(nums[i]);
        int ans1=money(a);
    
        //exclude first
        for(int i=1;i<n;i++) b.push_back(nums[i]);
        int ans2=money(b);

        return max(ans1,ans2);

    }
};