#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        int mx = 0;

        vector<int> hash( 256, -1);
        int i = 0;
        int j = 0;
        while( j < n){
            if( hash[str[j]] != -1){
                if( hash[str[j]] >= i){
                    i = hash[str[j]] + 1;
                }
            }
            mx = max( mx, j - i +1);
            hash[str[j]] = j;
            j++;
        }
       
        return mx;
    }
};