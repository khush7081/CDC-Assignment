#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();

        unordered_map<char, vector<int> > m1;
        unordered_map<char, vector<int> > m2;

        for( int i = 0 ; i < n; i++){
            m1[secret[i]].push_back(i);
            m2[guess[i]].push_back(i);
        }
        int bulls = 0;
        int cows = 0;
        
        for( auto it : m1){

            char ch = it.first;
            if( m2.find(ch) == m2.end()) continue;

            // present in guess
            if( it.second.size() == 1 && m2[ch].size() == 1){
                int freq = it.second[0];
                if( m2[ch][0] == freq) bulls++;
                else cows++;


            }
            else if( it.second.size() == 1) {
                bool flag = false;
                vector<int>temp = m2[ch];
                for( int idx : temp){
                    if( idx == it.second[0]){
                        flag = true;
                        bulls++;
                        break;
                    }
                }
                if( flag == false) cows++;
                
            }

            else if( m2[ch].size() == 1) {
                bool flag = false;
                vector<int>temp = it.second;
                for( int idx : temp){
                    if( idx == m2[ch][0]){
                        bulls++;
                        flag = true;
                        break;
                    }
                }
                if( flag == false) cows++;
              
            }
            else{
            
                vector<int>a = it.second;
                vector<int>b = m2[ch];

                int i = 0;
                int j = 0;

                int c1 = min(a.size(), b.size());
        
                while( i < a.size() && j < b.size()){
                    if( a[i] == b[j]){
                        bulls++;
                        c1--;
                        i++;
                        j++;
                    }
                    else if( a[i] < b[j]) i++;
                    else j++;
                }
                cows += c1;
              
            }
            
        }
       
        string ans = (to_string)(bulls) + "A" + (to_string)(cows)+ "B";
        return ans;


        
    }
};