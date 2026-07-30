class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr = prices[0];
        int ans = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > curr) {
                ans += prices[i] - curr;
                curr = prices[i];      
            } else {
                curr = prices[i];    
            }
        }

        return ans;
    }
};