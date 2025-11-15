#include<iostream>
#include<vector>
using namespace std;
 int partition(vector<int>& nums, int low, int high) {
        
        int mid = low + (high - low) / 2;
        int pivotIndex = low;

        if ((nums[low] <= nums[mid] && nums[mid] <= nums[high]) || (nums[high] <= nums[mid] && nums[mid] <= nums[low]))
            pivotIndex = mid;
        else if ((nums[mid] <= nums[high] && nums[high] <= nums[low]) || (nums[low] <= nums[high] && nums[high] <= nums[mid]))
            pivotIndex = high;

      
        swap(nums[pivotIndex], nums[high]);
        int pivot = nums[high];

        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low >= high) return;  
        int p = partition(nums, low, high);
        quicksort(nums, low, p - 1);
        quicksort(nums, p + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }