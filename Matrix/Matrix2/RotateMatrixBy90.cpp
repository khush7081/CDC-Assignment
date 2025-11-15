#include<iostream>
#include<vector>
using namespace std;
  void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) matrix[i][j]=matrix[i][j];
                if(i<j){
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        // REVERSE 
        for(int i=0;i<n;i++){
        int b=n-1;
            for(int j=0;j<n;j++){
                if(j>b) break;
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][b];
                matrix[i][b]=temp;
                b--;
            }
        }
        
    }