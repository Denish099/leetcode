class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    continue;
                }

                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int down = 0;
                int right = 0;
                if (i > 0) {
                    down = dp[i - 1][j];
                }
                if (j > 0) {
                    right = dp[i][j - 1];
                }

                dp[i][j] = down + right;
            }
        }

        return dp[m-1][n-1];
    }
};