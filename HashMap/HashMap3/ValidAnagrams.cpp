#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<s.length();i++) m1[s[i]]++;
        for(int i=0;i<t.length();i++) m2[t[i]]++;
        for(auto x:m1){
            char ch=x.first;
            int freq=x.second;
            if(m2.find(ch)==m2.end()) return false;
            else{
                if(freq!=m2[ch]) return false;
            }
        }
        return true;
        
    }
};