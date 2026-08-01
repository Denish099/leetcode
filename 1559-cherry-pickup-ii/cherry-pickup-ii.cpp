class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> dp;
    int helper(vector<vector<int>>& grid, int i, int col1, int col2) {

        if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) {
            return -1e9;
        }

        if (i == m - 1) {
            if (col1 == col2) {
                return grid[i][col1];
            } else {
                return grid[i][col1] + grid[i][col2];
            }
        }

        if (dp[i][col1][col2] != -1) {
            return dp[i][col1][col2];
        }
        int cheery;
        if (col1 == col2) {
            cheery = grid[i][col1];
        } else {
            cheery = grid[i][col1] + grid[i][col2];
        }

        return dp[i][col1][col2] =
                   cheery + max({
                                helper(grid, i + 1, col1 + 1, col2),
                                helper(grid, i + 1, col1 + 1, col2 + 1),
                                helper(grid, i + 1, col1 + 1, col2 - 1),
                                helper(grid, i + 1, col1, col2),
                                helper(grid, i + 1, col1, col2 + 1),
                                helper(grid, i + 1, col1, col2 - 1),
                                helper(grid, i + 1, col1 - 1, col2),
                                helper(grid, i + 1, col1 - 1, col2 + 1),
                                helper(grid, i + 1, col1 - 1, col2 - 1),
                            });
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return helper(grid, 0, 0, n - 1);
    }
};