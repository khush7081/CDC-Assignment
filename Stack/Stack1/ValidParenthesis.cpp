#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
        int len=s.length();
        stack<char>st;
        for(int i=0;i<len;i++){
            if(s[i]=='(') st.push(s[i]);
            if(s[i]=='[') st.push(s[i]);
            if(s[i]=='{') st.push(s[i]);
            else if(s[i]==')'){
                if(st.size() && st.top()=='(') st.pop();
                else return false;
            }
             else if(s[i]==']'){
                if(st.size() && st.top()=='[') st.pop();
                else return false;
            }
             else if(s[i]=='}'){
                if(st.size() && st.top()=='{') st.pop();
                else return false;
            }
        }
        if(st.size()==0) return true;
        return false;

    }