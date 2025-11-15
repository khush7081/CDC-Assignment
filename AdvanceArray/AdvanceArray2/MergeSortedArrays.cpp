#include<iostream>
#include<vector>
using namespace std;
  void merge(vector<int>& a, int m, vector<int>& b, int n) {
    
        // ( SHELL SORT )
        int len = m+n;
        int gap = (m+n)/2 + (gap%2);
        while( gap > 0){
            int i=0;
            int j= i + gap;
            while(j < len){
                if(a[i] > a[j]) swap(a[i],a[j]);
                i++;
                j++;
            }
            if( gap ==1) break;
            else gap = (gap/2) + (gap%2);
        }


    }