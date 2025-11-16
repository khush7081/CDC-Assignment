#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        
        unordered_map<char, int>mp;
        int mx = -1;
        char ans;
        for(auto c : s){
            mp[c]++;
            if( mp[c] > mx){
                mx = mp[c];
                ans = c;
            }
            else if(mp[c] == mx){
                ans = min(ans, c);
            }
        }
        return ans;
        
    }
};