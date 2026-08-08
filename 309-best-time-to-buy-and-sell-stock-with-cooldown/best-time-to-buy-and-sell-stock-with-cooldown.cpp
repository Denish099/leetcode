class Solution {
public:
    int arr[5001][2] = {-1};
    int solve(int day, vector<int>& prices, int n, bool buy) {
        if (day >= n) {
            return 0;
        }

        if(arr[day][buy] != -1){
            return arr[day][buy];
        }

        int profit = 0;

        if (buy) {
            int take = solve(day + 1, prices, n, false) - prices[day];
            int notTake = solve(day + 1, prices, n, true);

            profit = max({take, notTake, profit});
        } else {
            int sell = prices[day] + solve(day + 2, prices, n, true);
            int notSell = solve(day + 1, prices, n, false);

            profit = max({sell, notSell, profit});
        }

        return arr[day][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(arr,-1,sizeof(arr));
        return solve(0,prices,prices.size(),true);
    }
};