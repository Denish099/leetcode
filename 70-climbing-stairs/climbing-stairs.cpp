class Solution {
public:
    // int helper(int n){
    //     if(n == 0){
    //         return 1;
    //     }
    //     if(n < 0){
    //         return 0;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     return dp[n] = helper(n-1) + helper(n-2);
    // }
    int climbStairs(int n) {
        vector<int> dp(n + 2, -1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};