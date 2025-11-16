#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
void generate(vector<string>&v, string ans,int n, int opening, int closing){
    if(opening>n || closing>n) return;
    if(opening==n && closing ==n) {
        v.push_back(ans);
        return;
    }
     generate(v,ans+"(",n,opening+1,closing);
     if(opening>closing) generate(v,ans+")",n,opening,closing+1);
}

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generate(v,"",n,0,0);
        return v;    
    }
};