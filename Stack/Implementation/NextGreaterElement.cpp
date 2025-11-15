#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
 vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        stack<int>st;
        st.push( b[m-1]);
        //vector<int> nge(m);
        unordered_map<int,int> mp;
        mp[b[m-1]] = -1;
        //nge[m-1] = -1;
        for(int i = m-2; i >= 0 ;i--){
            while( st.size() && st.top() <= b[i]){
                st.pop();
            }
            if( st.size()) mp[b[i]] = st.top();
            else mp[b[i]] = -1;
            st.push(b[i]);
        }
        vector<int>ans;
        for(int i = 0; i < n ;i++){
            ans.push_back( mp[a[i]]);
        }
        return ans;  
    }