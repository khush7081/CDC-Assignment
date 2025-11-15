#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();

        // previous greatest element array 

        vector<int>v2(n);
        int max = height[0];
        v2[0] = -1;
        for(int i = 1 ; i<n;i++ ){
            v2[i]=max;
            if( height[i] > max) max = height[i];
        }

        // next greatest element array 

        vector<int>v3(n);
        
        int max2=height[n-1];

        for(int i =n-2; i>=0;i-- ){
            v3[i]=max2;
            if(height[i] > max2) max2=height[i];        
        }
        v3[n-1]=-1;
        
        for(int i =0;i<n;i++){
            if(v2[i]<v3[i]) v2[i]=v2[i];
            else v2[i]=v3[i];
        }

        int water=0;
        for(int i=0;i<n;i++){
            if(v2[i]>height[i]) water+=(v2[i]-height[i]);
        }

        return water;

    }