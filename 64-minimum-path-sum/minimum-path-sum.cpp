class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    long long helper(vector<vector<int>>& grid, int i, int j) {
        if (i >= m || j >= n) {
            return INT_MAX;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = min(grid[i][j] + helper(grid, i + 1, j),
                   grid[i][j] + helper(grid, i, j + 1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m + 1, vector<int>(n + 1, -1));
        return helper(grid, 0, 0);
    }
};