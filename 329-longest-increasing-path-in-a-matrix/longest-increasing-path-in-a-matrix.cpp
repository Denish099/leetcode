class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        vector<int> mx = {1, 0, -1, 0};
        vector<int> my = {0, 1, 0, -1};

        auto dfs = [&](auto&& self, int i, int j) -> int {
            if (memo[i][j] != 0) {
                return memo[i][j];
            }

            for (int k = 0; k < 4; k++) {
                int nr = i + mx[k];
                int nc = j + my[k];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    matrix[nr][nc] > matrix[i][j]) {
                    memo[i][j] = max(memo[i][j], 1 + self(self, nr, nc));
                }
            }

            return memo[i][j];
        };
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(dfs, i, j));
            }
        }

        return ans + 1;
    }
};