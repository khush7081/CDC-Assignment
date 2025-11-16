#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int count(int n){
        int c = 0;
        while( n > 0){
            c++;
            n = n & n-1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};