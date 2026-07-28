class Solution {
public:
    // int helper(int idx, vector<int>& cost) {
    //     if (idx >= cost.size()) {
    //         return 0;
    //     }

    //     if (dp[idx] != -1) {
    //         return dp[idx];
    //     }

    //     return dp[idx] = cost[idx] + min(helper(idx + 1, cost), helper(idx +
    //     2, cost));
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1){
            return 0;
        }
        vector<int> dp(n+2, -1);

        dp[n] = 0;
        dp[n+1] = 0;

        for(int i = n-1;i>=0;i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }

        return dp[0] > dp[1] ? dp[1] : dp[0];
        
    }
};