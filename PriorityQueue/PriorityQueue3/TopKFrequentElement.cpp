#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int e : nums){
            mp[e]++;
        }
        priority_queue< pair<int,int>>pq;
        for(auto p : mp){
            pq.push( {p.second, p.first});
        }
        vector<int>ans;
        for(int i = 1; i <= k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;


        
    }
};