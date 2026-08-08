class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        auto solve = [&](auto&& self, int day, int buy, int k) -> int {
            if (day >= n || k >= 2) {
                return 0;
            }

            if (dp[day][buy][k] != -1) {
                return dp[day][buy][k];
            }

            int profit = 0;

            if (buy) {
                int take = self(self, day + 1, false, k) - prices[day];

                int notTake = self(self, day + 1, true, k);

                profit = max(take, notTake);
            }
            else {
                int sell = prices[day] + self(self, day + 1, true, k + 1);

                int notSell = self(self, day + 1, false, k);

                profit = max(sell, notSell);
            }

            return dp[day][buy][k] = profit;
        };

        return solve(solve, 0, true, 0);
    }
};