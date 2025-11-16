#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        if( bills[0] != 5) return false;

        vector<int> count(3,0);
        

        for(int i = 0 ; i < n; i++){
            if( bills[i] == 5){
                count[0]++;
             
            }
            else if( bills[i] == 10){
                
                if( count[0] > 0){
                  
                    count[1]++;
                    count[0]--;
                }
                else return false;
            }
            else{
                if( count[0] == 0) return false;    // no 5$ bills left so we cannot return 15$

                else if( count[1] == 0){
                    if( count[0] < 3) return false;
                    else{
                        count[0] -= 3;
                        count[2]++;
                       
                    }
                }
                else{
                    count[0]--;
                    count[1]--;
                    count[2]++;
                }

            }
        }

        return true;
        
    }
};