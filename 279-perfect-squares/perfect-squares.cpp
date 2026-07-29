class Solution {
public:
    vector<int> arr;
    int numSquares(int n) {
        arr.resize(102, 0);
        for (int i = 1; i <= 100; i++) {
            arr[i - 1] = i * i;
        }
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (auto a : arr) {
            for (int i = 0; i <= n; i++) {
                if (i - a >= 0) {
                    dp[i] = min(dp[i - a] + 1, dp[i]);
                }
            }
        }

        return dp[n];
    }
};