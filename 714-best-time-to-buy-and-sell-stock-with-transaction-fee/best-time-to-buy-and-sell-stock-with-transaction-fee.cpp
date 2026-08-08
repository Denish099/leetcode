class Solution {
public:
    vector<vector<int>> dp;

    int solve(int day, vector<int>& prices, int fee, bool buy) {
        if (day >= prices.size()) {
            return 0;
        }

        if (dp[day][buy] != -1) {
            return dp[day][buy];
        }

        int profit;

        if (buy) {
            int take = solve(day + 1, prices, fee, false) - prices[day];
            int notTake = solve(day + 1, prices, fee, true);

            profit = max(take, notTake);
        } 
        else {
            int sell = prices[day] - fee +
                       solve(day + 1, prices, fee, true);

            int notSell = solve(day + 1, prices, fee, false);

            profit = max(sell, notSell);
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        dp.assign(prices.size(), vector<int>(2, -1));

        return solve(0, prices, fee, true);
    }
};