class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int helper(vector<vector<int>>& grid, int r, int c, int k) {
        if (r >= m || c >= n) return INT_MIN;
        if (k < 0) return INT_MIN;

        if (r == m - 1 && c == n - 1) {
            int cost = (grid[r][c] == 0 ? 0 : 1);
            if (k - cost < 0) return INT_MIN;
            return grid[r][c];
        }

        if (dp[r][c][k] != -1) return dp[r][c][k];

        int cost = (grid[r][c] == 0 ? 0 : 1);
        int newK = k - cost;

        int right = helper(grid, r, c + 1, newK);
        int down  = helper(grid, r + 1, c, newK);

        int best = max(right, down);

        if (best == INT_MIN) {
            return dp[r][c][k] = INT_MIN;
        }

        return dp[r][c][k] = grid[r][c] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<int>>>(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1))
        );

        int ans = helper(grid, 0, 0, k);

        return (ans == INT_MIN ? -1 : ans);
    }
};