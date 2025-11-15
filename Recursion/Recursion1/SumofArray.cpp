#include<iostream>
#include<vector>
using namespace std;
int s( vector<int>& arr, int idx){
        if( idx < 0) return 0;
        return arr[idx] + s(arr, idx-1);
    }
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        int n = arr.size();
        return s(arr, n-1);
        
    }