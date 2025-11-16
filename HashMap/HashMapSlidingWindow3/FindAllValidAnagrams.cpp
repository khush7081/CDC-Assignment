#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        unordered_map<char,int>mp;

        for(char c : p) mp[c]++;

        vector<int>ans;
        int count = 0;

        int i = 0;
        int j = 0;

        while( j < n){
            if( mp[s[j]] > 0) count++;
            mp[s[j]]--;

            while( count == m){
                if(j - i + 1 == m) ans.push_back(i);
                mp[s[i]]++;
                if( mp[s[i]] > 0) count--;
                i++;
            }
            j++;
        }

        return ans;
        
    }
};