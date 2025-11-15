#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls[n-1] -stalls[0];
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            int cows = k-1;
            int prevPos = 0;
            for(int i = 1; i < n; i++){
                if(stalls[i] - stalls[prevPos] >= mid){
                    cows--;
                    prevPos = i;
                }
            }
            if(cows <= 0){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
    }
};