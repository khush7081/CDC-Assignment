#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int perform(int a, int b, string c){
       if( c == "+") return a + b;
       if( c == "-") return a - b;
       if( c == "/") {
           if( a<0 && b<0){
               return a / b;
           }
           if( a < 0){
               if( -a % b == 0) return a/b;
               else return a/b - 1;
           }
           if( b < 0){
               if( a % -b == 0) return a/b;
               else return a/b - 1;
           }
           return a / b;
       }
       if( c == "*") return a * b;
       if( c == "^") return pow(a,b);
   }
    int evaluatePostfix(vector<string>& arr) {
        stack<int>st;
        int n =arr.size();
        for(int i = 0; i <n; i++){
    
            if( arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/" || arr[i] == "^") {
                int v2 = st.top();
                st.pop();
                int v1 = st.top();
                st.pop();
                int v = perform(v1,v2, arr[i]);
                st.push(v);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }