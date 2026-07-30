class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        
        for (auto price : prices) {
            mini = min(mini, price);
            maxi = max(maxi, price - mini);
        }

        return maxi;
    }
};