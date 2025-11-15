#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> Smallestonleft(int arr[], int n) {
    set<int>s;
    vector<int>ans(n);
    ans[0] = -1;
    s.insert(arr[0]);
    for(int i = 1; i < n; i++){
        s.insert(arr[i]);
        auto p = s.find(arr[i]);
        if (p == s.begin()) ans[i] = -1;
        else ans[i] = *prev(p);
    }
    return ans;
}