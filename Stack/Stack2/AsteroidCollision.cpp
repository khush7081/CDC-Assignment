#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        for(int i = 0; i < n; i++){

            if(st.size() == 0) st.push(nums[i]);

            else if( nums[i] >= 0) st.push(nums[i]);

            else{
                bool destroyed = false;

                if(st.top() < 0){
                    st.push( nums[i]);
                    continue;
                }
                else if( st.size() && -nums[i] == st.top()){
                    st.pop();
                    continue;
                }
                while( st.size() &&  -nums[i] >= st.top()){
                    if(st.top() < 0){
                        st.push( nums[i]);
                        break;
                    }
                    else if ( -nums[i] == st.top()){
                        st.pop();
                        destroyed = true;
                        break;
                    }
                    st.pop();
                }
                if( !destroyed && st.size() == 0) st.push(nums[i]);
            }
        }
        if(st.size() == 0) return {};
        n = st.size();
        vector<int>ans(n);
        while(st.size()){
            ans[n-1] = st.top();
            st.pop();
            n--;
        }
        return ans;

    }