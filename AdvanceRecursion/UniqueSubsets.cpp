#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    void subsets(int idx, vector<int>&arr, vector<int>v, vector<vector<int>>& ans){
        if( idx == arr.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(arr[idx]);
        subsets(idx+1, arr, v, ans);
        v.pop_back();
        
        while( idx + 1 < arr.size() && arr[idx] == arr[idx+1]) idx++;
        subsets(idx+1, arr, v, ans);
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        vector<int>v;
        subsets(0, arr, v, ans);
        return ans;
    }
};