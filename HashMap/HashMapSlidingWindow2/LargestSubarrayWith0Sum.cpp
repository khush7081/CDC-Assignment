#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;
        
        unordered_map<int,int>mp;
        mp[0] = - 1;
        int presum = 0;
        for(int i = 0; i < n; i++){
            presum += arr[i];
            
            int tar = presum - 0;
            if( mp.find(tar) != mp.end()){
                mx = max(mx, i - mp[tar]);
            }
            
            if( mp.find(presum) == mp.end()){
                mp[presum] = i;
            }
            
        }
        return mx;
        
    }
};