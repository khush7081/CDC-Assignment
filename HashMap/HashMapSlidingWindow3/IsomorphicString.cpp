#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp;
        int n = s.length();
        for(int i = 0 ; i < n; i++){
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = t[i];
            else{
                if( mp[s[i]] != t[i]) return false;
            }
        }

        unordered_map<char, char> mp2;
        for(int i = 0 ; i < n; i++){
            if(mp2.find(t[i]) == mp2.end()) mp2[t[i]] = s[i];
            else{
                if( mp2[t[i]] != s[i]) return false;
            }
        }
        return true;

        
    }
};