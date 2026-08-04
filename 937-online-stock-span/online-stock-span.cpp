class StockSpanner {
public:
    vector<int> nums;
    int i;
    StockSpanner() { i = -1; }

    int next(int price) {

        int count = 1;

        for (int j = i; j >= 0; j--) {
            if (nums[j] <= price) {
                count++;
            } else {
                break;
            }
        }
        nums.push_back(price);
        i++;

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */