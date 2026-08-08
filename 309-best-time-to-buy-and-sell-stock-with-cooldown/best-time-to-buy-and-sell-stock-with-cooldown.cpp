class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buyable = 0;
        int hold = INT_MIN;
        int cooldown = INT_MIN;

        for (int price : prices) {

            int newBuyable = max(buyable, cooldown);
            int newHold = max(hold, buyable - price);
            int newCooldown = hold + price;

            buyable = newBuyable;
            hold = newHold;
            cooldown = newCooldown;
        }

        return max(buyable, cooldown);
    }
};