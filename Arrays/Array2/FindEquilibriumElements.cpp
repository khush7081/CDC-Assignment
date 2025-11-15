#include<iostream>
#include<vector>
using namespace std;
int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];

        int idx=-1;
        for(int i=0;i<n;i++){
            if(i==0){
                if(pre[n-1]-pre[i]==0){
                     idx=0;
                     break; 
                }
            }
            else if(i==n-1){
                if(pre[i-1]==0){ 
                    idx=n-1;
                    break;
                }
            }
            else{ 
                if(pre[i-1]==(pre[n-1]-pre[i])){
                    idx=i;
                    break;
                }
            }
        }

        return idx;
    }