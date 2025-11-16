#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int G=g.size();
        int S=s.size();
        int count=0;
        int i=0,j=0;

        while(i<G && j<S){
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return count; 
    }
};