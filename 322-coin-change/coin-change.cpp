class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& coins, int amount, int idx) {
        if (amount < 0) {
            return 1e9;
        }
        if (amount == 0) {
            return 0;
        }

        int count = INT_MAX;
        if (idx >= coins.size()) {
            return 1e9;
        }
        if (dp[amount][idx] != -1) {
            return dp[amount][idx];
        }

        count = min(helper(coins, amount, idx + 1),
                    1 + helper(coins, amount - coins[idx], idx));

        return dp[amount][idx] = count;
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        dp.resize(amount + 1, vector<int>(coins.size() + 1,-1));

        int ans = helper(coins, amount, 0);

        return ans == 1e9 ? -1 : ans;
    }
};