#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(m.find(x)==m.end()) m[nums[i]]=i;
            else{
                ans.push_back(m[x]);
                ans.push_back(i);
            }
        }
        return ans;

    }
};