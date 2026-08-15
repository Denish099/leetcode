class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {

                int left = INT_MAX;
                int right = INT_MAX;

                if (j > 0) {
                    left = dp[i - 1][j - 1];
                }

                if (j < i) {
                    right = dp[i - 1][j];
                }

                dp[i][j] = triangle[i][j] + min(left, right);
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};