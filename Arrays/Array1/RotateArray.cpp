#include<iostream>
#include<vector>
using namespace std;
void reversepart(vector<int> &nums, int a, int b){
        for(int i=a, j=b; i<=j; i++,j--){
            if(i>j) break;
            int temp= nums[i];
            nums[i]=nums[j];
            nums[j]= temp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k % n;
        reversepart(nums, 0, n-1-k);
        reversepart(nums, n-k, n-1);
        reversepart(nums, 0 , n-1);
    }