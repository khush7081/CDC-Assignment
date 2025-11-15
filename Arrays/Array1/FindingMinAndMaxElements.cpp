#include<iostream>
#include<vector>
using namespace std;
int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mndx = 0;
        int mxdx = 0;
        if( n == 1) return 1;
        for(int i = 0; i < n; i++){
            if( nums[i] > nums[mxdx]) mxdx = i;
            else if( nums[i] < nums[mndx]) mndx = i;
        }
        int a = 0, b = 0, c = 0;
        int mn = mndx;
        int mx = mxdx;
        for(int i = 0; i < n; i++){
            a++;
            if( i == mndx) mn = -1;
            if( i == mxdx) mx = -1;
            if( mn == -1 && mx == -1) break;
        }

        mn = mndx, mx = mxdx;

        for(int i = n-1; i>=0; i--){
            b++;
            if( i == mndx) mn = -1;
            if( i == mxdx) mx = -1;
            if( mn == -1 && mx == -1) break;

        }

        mn = mndx, mx = mxdx;

        for(int i = 0; i < n; i++){
            c++;
            if( i == mndx || i == mxdx) break;

        }
        for(int i = n-1; i >= 0; i--){
            c++;
            if( i == mndx || i == mxdx) break;
        }

        return min(a, min(b,c));
        
    }