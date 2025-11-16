#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
   void combinations(int idx, int n, int k, vector<int>&v, vector<vector<int>>& ans){
        if(k == 0){ 
            ans.push_back(v);
            return;
        }
        for(int i = idx; i <= n ; i++){
            v.push_back(i);
            combinations(i + 1, n, k-1, v, ans);
            v.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        combinations(1, n, k, v, ans);
        return ans;
    }
};