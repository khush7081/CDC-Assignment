#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool valid( vector<string> board, int row, int col, int n){
        
        // horizontal check
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q') return false;
        }
        // ALL 4 DIAGONALS
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){           // up left
            if(board[i][j] == 'Q') return false;
        }
       
        for(int i=row, j=col; i<n && j>=0; i++, j--){                 // down left
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void f( vector<vector<string>>& ans, vector<string> &board, int col, int n){
        if( col == n){
            ans.push_back(board);
            return;
        }
        for(int i =0; i<n; i++){
            if( valid(board, i, col,n)){
                board[i][col] = 'Q';
                f(ans, board, col+1, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        f( ans, board, 0,n);
        return ans;   
    }
};