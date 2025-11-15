#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++) m[nums[i]]++;
        int maxx=-2;
        for(auto p:m){
            maxx=max(maxx,p.second);
        }
        int count=0;
        for(auto p:m){
            if(maxx==p.second) count+=p.second;
        }
        return count;
   
    }