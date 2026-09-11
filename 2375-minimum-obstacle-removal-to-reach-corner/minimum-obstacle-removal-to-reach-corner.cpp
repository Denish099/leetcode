class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> mx = {0, 0, 1, -1};
        vector<int> my = {1, -1, 0, 0};

        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;


        if (grid[0][0] == 1) {
            vis[0][0] = 1;
        } else {
            vis[0][0] = 0;
        }

        dq.push_front({0, 0});

        while (!dq.empty()) {

            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {

                int nx = x + mx[i];
                int ny = y + my[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int cost;

                    if (grid[nx][ny] == 1) {
                        cost = 1;
                    } else {
                        cost = 0;
                    }

                    if (vis[x][y] + cost < vis[nx][ny]) {

                        vis[nx][ny] = vis[x][y] + cost;

                        if (cost == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        return vis[m - 1][n - 1];
    }
};