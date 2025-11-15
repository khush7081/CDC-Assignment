#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    stack<long long>st;
    long long mn=LLONG_MAX;
    
    MinStack() {
        
    }
    
    void push(int val) {
      
        long long x=(long long)val;
        if(st.size()==0){
            st.push(x);
            mn=x;
        }
        else if(x >= mn) st.push(x);
        else{
            st.push(2*x -mn);
            mn=x;
        }
    }
    
    void pop() {
         
        if(st.top()<mn){
            long long oldmin=2*mn-st.top();
            mn=oldmin;
        }
        st.pop();
    }
    
    int top() {
        
        if(st.top()<mn) return (int)mn;
        else return (int)(st.top());

    }
    
    int getMin() {
        
        return int(mn);
        
    }
};