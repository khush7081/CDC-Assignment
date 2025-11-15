 #include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
 vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort( a.begin(), a.end());
        sort( b.begin(), b.end());
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        unordered_set<int>s;
        while( i <n && j < m){
            if( a[i] == b[j]){
                s.insert( a[i]);
                i++; j++;
            }
            else if( a[i] < b[j]) i++;
            else j++;
        }
        vector<int>ans(s.begin(), s.end());
        return ans;
    }