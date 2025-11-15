#include<iostream>
using namespace std;
class stack{
public:
    int idx=-1;
    int a[5];
    void display(){
        for(int i=0;i<=idx;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    void push(int val){
        if(idx==4){
            cout<<"stack overflow "<<endl;
            return;
        }
        idx++;
        a[idx]=val;
    }
    void pop(){
        if(idx==-1){
            cout<<"stack underflow "<<endl;
            return;
        }
        idx--;
    }
    int top(){
        if(idx==-1){
            cout<<"stack underflow "<<endl;
            return -1;
        }
        return a[idx];
    }
    int size(){
        return idx+1;
    }
};
int main(){
    cout<<"size of stack = 5 "<<endl;
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.pop();
    st.display();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
}