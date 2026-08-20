class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int size = strs.size();

        vector<vector<vector<int>>> dp(
            size + 1,
            vector<vector<int>>(m + 1, vector<int>(n + 1, 0))
        );

        for (int i = 1; i <= size; i++) {

            int countZ = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int countO = strs[i - 1].size() - countZ;

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {

                    dp[i][j][k] = dp[i - 1][j][k];

                    if (countZ <= j && countO <= k) {
                        dp[i][j][k] = max(
                            dp[i][j][k],
                            1 + dp[i - 1][j - countZ][k - countO]
                        );
                    }
                }
            }
        }

        return dp[size][m][n];
    }
};