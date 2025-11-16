#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    
    void dfs( int r, int c, int currcolor, int color, int n, int m, vector<vector<int>>& image){
        
        image[r][c] = color;
       
            if( r + 1 < n && image[r+1][c] == currcolor){
                dfs( r+1, c, currcolor, color, n, m, image);
            }
            if( r -1 >= 0 &&  image[r-1][c] == currcolor){
                dfs( r-1, c, currcolor, color, n, m, image);
            }
            if( c + 1 < m &&  image[r][c+1] == currcolor){
               dfs( r, c+1, currcolor, color, n, m, image);
            }
            if( c -1 >= 0 &&  image[r][c-1] == currcolor){
               dfs( r, c-1, currcolor, color, n, m, image);
            }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
      
        if( image[sr][sc] == color) return image;

        dfs( sr, sc, image[sr][sc], color, n , m, image);
        return image;
    }
};