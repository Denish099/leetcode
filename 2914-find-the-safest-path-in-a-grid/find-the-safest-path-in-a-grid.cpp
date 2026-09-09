class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};

  
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }


        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if (dist[nx][ny] != -1)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }


        auto can = [&](int k) -> bool {
            if (dist[0][0] < k)
                return false;

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int, int>> q;

            q.push({0, 0});
            vis[0][0] = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1)
                    return true;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    if (vis[nx][ny])
                        continue;

                    if (dist[nx][ny] < k)
                        continue;

                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            return false;
        };

        int low = 0;
        int high = 2 * n;  

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (can(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};