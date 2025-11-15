#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class StockSpanner {
public:
    vector<int>v;
    vector<int>pge;
    stack<int>st;
    int size;
    StockSpanner() {
        size = 0;        
    }
    
    int next(int price) {
        v.push_back(price);
        if(size == 0) pge.push_back(-1);
        if(size == 0) st.push(0);
        size++;
        int n = v.size();
        if( n == 1) return 1;
        while(st.size() && v[st.top()] <= v[n-1]){
            st.pop();
        }
        if(st.size()) pge.push_back(st.top());
        else pge.push_back(-1);
        st.push(n-1);

        return (n-1) - pge[n-1];
    }
};