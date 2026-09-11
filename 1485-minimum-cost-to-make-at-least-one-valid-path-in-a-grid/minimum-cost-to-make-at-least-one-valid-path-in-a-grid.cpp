class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> mx = {0, 0, 1, -1};
        vector<int> my = {1, -1, 0, 0};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        dq.push_front({0, 0});
        dist[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 1; i <= 4; i++) {

                int nx = x + mx[i - 1];
                int ny = y + my[i - 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

                    int cost;

                    if (grid[x][y] == i)
                        cost = 0;
                    else
                        cost = 1;

                    if (dist[x][y] + cost < dist[nx][ny]) {

                        dist[nx][ny] = dist[x][y] + cost;

                        if (cost == 0)
                            dq.push_front({nx, ny});
                        else
                            dq.push_back({nx, ny});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};