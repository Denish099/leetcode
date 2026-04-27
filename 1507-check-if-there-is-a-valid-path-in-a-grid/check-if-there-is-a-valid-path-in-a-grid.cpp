class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        auto goLeft  = [](int p) { return p == 1 || p == 3 || p == 5; };
        auto goRight = [](int p) { return p == 1 || p == 4 || p == 6; };
        auto goDown  = [](int p) { return p == 2 || p == 3 || p == 4; };
        auto goUp    = [](int p) { return p == 2 || p == 5 || p == 6; };

        function<bool(int,int)> dfs = [&](int r, int c) -> bool {
            if (r == m - 1 && c == n - 1)
                return true;

            vis[r][c] = true;
            int type = grid[r][c];

            if (c - 1 >= 0 && !vis[r][c - 1] &&
                goLeft(type) && goRight(grid[r][c - 1])) {
                if (dfs(r, c - 1)) return true;
            }

            if (c + 1 < n && !vis[r][c + 1] &&
                goRight(type) && goLeft(grid[r][c + 1])) {
                if (dfs(r, c + 1)) return true;
            }

            if (r - 1 >= 0 && !vis[r - 1][c] &&
                goUp(type) && goDown(grid[r - 1][c])) {
                if (dfs(r - 1, c)) return true;
            }

            if (r + 1 < m && !vis[r + 1][c] &&
                goDown(type) && goUp(grid[r + 1][c])) {
                if (dfs(r + 1, c)) return true;
            }

            return false;
        };

        return dfs(0, 0);
    }
};