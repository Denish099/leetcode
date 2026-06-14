class Solution {
public:
    vector<int> dp;

    int helper(int i, int n) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = helper(i + 1, n) + helper(i + 2, n);
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return helper(0, n);
    }
};