    #include<iostream>
    #include<unordered_set>
    using namespace std;

    string removeDuplicates(string &s) {
        string ans = "";
        unordered_set<char>st;
        for(char c : s){
            if(st.find(c) == st.end()){
                st.insert(c);
                ans += c;
            }
        }
        return ans;
    }