#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set< pair<int,int> >s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) s.insert({i, j});
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && s.find({i,j}) != s.end()){
                    for(int k=0;k<m;k++) matrix[i][k]=0;
                    for(int k=0;k<n;k++) matrix[k][j]=0;
                }
            }
        }

    }
};