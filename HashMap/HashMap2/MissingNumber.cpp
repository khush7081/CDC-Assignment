#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(int e : nums) s.insert(e);

        for(int i = 0; i <= n; i++){
            if(s.find(i) == s.end()) return i;
        }
        return 0;
    }
};