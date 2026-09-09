class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};


        vector<vector<int>> fire(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fire[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if (grid[nx][ny] == 2)
                    continue;

                if (fire[nx][ny] != -1)
                    continue;

                fire[nx][ny] = fire[x][y] + 1;
                q.push({nx, ny});
            }
        }

        auto can = [&](int wait) -> bool {
            vector<vector<int>> vis(m, vector<int>(n, -1));
            queue<pair<int, int>> q;

            if (fire[0][0] != -1 && wait >= fire[0][0])
                return false;

            q.push({0, 0});
            vis[0][0] = wait;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                int time = vis[x][y];

                if (x == m - 1 && y == n - 1)
                    return true;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (grid[nx][ny] == 2)
                        continue;

                    if (vis[nx][ny] != -1)
                        continue;

                    int newTime = time + 1;


                    if (nx == m - 1 && ny == n - 1) {
                        if (fire[nx][ny] == -1 ||
                            newTime <= fire[nx][ny]) {
                            return true;
                        }
                    }
                    else {

                        if (fire[nx][ny] != -1 &&
                            newTime >= fire[nx][ny]) {
                            continue;
                        }

                        vis[nx][ny] = newTime;
                        q.push({nx, ny});
                    }
                }
            }

            return false;
        };



        int low = 0;
        int high = 1e9;

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (can(mid))
                low = mid;
            else
                high = mid - 1;
        }


        if (!can(0))
            return -1;


        if (low == 1e9)
            return 1e9;

        return low;
    }
};