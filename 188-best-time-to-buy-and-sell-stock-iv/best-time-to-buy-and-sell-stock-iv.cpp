class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        auto solve = [&](auto&& self, int day, int buy, int t) -> int {
            if (day >= n || t >= k) {
                return 0;
            }

            if (dp[day][buy][t] != -1) {
                return dp[day][buy][t];
            }

            int profit = 0;

            if (buy) {
                // Buy
                int take = self(self, day + 1, false, t) - prices[day];

                // Don't buy
                int notTake = self(self, day + 1, true, t);

                profit = max(take, notTake);
            } else {
                // Sell -> transaction completed
                int sell = prices[day] + self(self, day + 1, true, t + 1);

                // Don't sell
                int notSell = self(self, day + 1, false, t);

                profit = max(sell, notSell);
            }

            return dp[day][buy][t] = profit;
        };

        return solve(solve, 0, true, 0);
    }
};
