
class Solution {
public:

    //  MEMOIZATION

    // int f(int n, vector<int>& dp){
    //     if( n == 0 || n == 1) return n;
    //     if( dp[n] != -1) return dp[n];
    //     return dp[n] = f(n-1, dp) + f(n-2, dp);
    // }

    int fib(int n) {
        // vector<int>dp(n+1, -1);
        // return f(n,dp);

        
        if( n == 0 || n == 1) return n ;
        int prev2 = 0;
        int prev = 1;
        for(int i = 0; i <= n-2; i++){
            int curr = prev  + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};