class Solution {
public:
    const int MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                for (int face = 1; face <= k; face++) {
                    if (face <= sum) {
                        dp[i][sum] =
                            (dp[i][sum] + dp[i - 1][sum - face]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};