#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
          int minr=0,minc=0;
    int maxr=m-1, maxc=n-1;
    vector<int>v;
    while(minr<=maxr && minc<=maxc){

    
    
        for(int j=minc;j<=maxc;j++){
            v.push_back(matrix[minr][j]);
        }
        minr++;

        if(maxr<minr || maxc<minc) break;

        for(int j=minr;j<=maxr;j++){
            v.push_back(matrix[j][maxc]);
        }
        maxc--;
        if(maxr<minr || maxc<minc) break;

        for(int j=maxc;j>=minc;j--){
            v.push_back(matrix[maxr][j]);
        }
        maxr--;

        if(maxr<minr || maxc<minc) break;

        for(int j=maxr;j>=minr;j--){
            v.push_back(matrix[j][minc]);
        }
        minc++;
    
    }
    return v;
        
    }