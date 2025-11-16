#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool f( string s, string p, int i, int j, vector<vector<int>>& dp){
        if( i == 0 && j == 0) return true;
        if( i > 0 && j == 0) return false;
        if( i == 0 && j > 0){
            for(int k = 1; k <= j; k++){
                if(p[k - 1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i - 1] == p[j - 1] || p[j-1] == '?') return dp[i][j] = f(s, p ,i-1, j-1, dp);
    
        if(p[j-1] == '*'){
            return dp[i][j] = f(s,p, i-1, j, dp) | f(s, p, i, j-1, dp);
        }
        return dp[i][j] = false;

    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        // vector<vector<int>> dp(n + 1 , vector<int>(m + 1, -1));
        // return f(s, p , n, m, dp);

        // TABULATION

        //vector<vector<bool>> dp(n + 1 , vector<bool>(m + 1, false));

        // dp[0][0] = true;

        // for(int i = 1; i<=n; i++) dp[i][0] = false;

        // for(int j =1; j <= m; j++){
        //     bool flag =  true;
        //     for(int k = 1; k <= j; k++){
        //         if(p[k - 1] != '*') {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[0][j] = flag;
        // }

        // for(int i =1; i<=n; i++){
        //     for(int j= 1; j <= m; j++){
        //         if(s[i -1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
        //         else if( p[j-1] == '*'){
        //             dp[i][j] = dp[i-1][j] | dp[i][j-1];
        //         }
        //         else dp[i][j] = false;
        //     }
        // }
        // return dp[n][m];

        // SPACE OPTIMISATION

        vector<bool>prev(m+1, false), curr( m+1, false);
        prev[0] = true;

        //for(int i = 1; i<=n; i++) curr[0] = false;

        for(int j =1; j <= m; j++){
            bool flag =  true;
            for(int k = 1; k <= j; k++){
                if(p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i =1; i<=n; i++){
            for(int j= 1; j <= m; j++){
                if(s[i -1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if( p[j-1] == '*'){
                    curr[j] = prev[j] | curr[j-1];
                }
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];

    }
};