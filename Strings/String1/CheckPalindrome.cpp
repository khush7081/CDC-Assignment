  #include<iostream>
  using namespace std;
  string remove(string s){
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90) ans+=s[i]+32;
            else if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57)) ans+=s[i];
         }
        return ans;
    }
    bool isPalindrome(string s) {
        string ans=remove(s);
        for(int i=0,j=ans.length()-1;i<=j;i++,j--){
            if(ans[i]!=ans[j]) return false;
        }
        return true;
    }