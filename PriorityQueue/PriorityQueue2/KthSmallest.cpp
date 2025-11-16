#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue< int, vector<int>, greater<int>>pq(arr.begin(), arr.end());
       
        for(int i = 1; i < k; i++){
            pq.pop();
        }
        return pq.top();
    }
};