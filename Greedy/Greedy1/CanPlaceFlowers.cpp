#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        if(n==0) return true;
        if(s==1){
            if(flowerbed[0]==0) return true;
            else return false;
        }
        int count=0;
        for(int i=0;i<s;i++){
            if(i==0){
                if(flowerbed[i]==0 && flowerbed[i+1]!=1){
                    flowerbed[i]=1;
                    count++;
                }
            }
            else if(i==s-1){
                if(flowerbed[i]==0 && flowerbed[i-1]!=1){
                    flowerbed[i]=1;
                    count++;
                }

            }
            else if(flowerbed[i]==0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                flowerbed[i]=1;
                count++;
            }
        }
        if(count>=n) return true;
        return false;

    }
};