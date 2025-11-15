#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int>st;
    stack<int>temp;
    MyQueue() {
    }
    void push(int x) {
        

        while(st.size() > 0){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(temp.size() > 0){           // POP ND PEEK EFFICIENT
            st.push(temp.top());
            temp.pop();
        }
    }
    int pop(){
        
        int x=st.top();
        st.pop();             //POP ND PEEK EFFICIENT
        return x;
    }
    
    int peek() {
         
        return st.top();
    }
    bool empty() {
        if(st.size()==0) return true;
        return false;
    }
};