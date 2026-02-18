class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

        distance[0][0] = 1;
        pq.push({1, {0, 0}});

        int dr[] = {0, 1, 0, -1, 1, 1, -1, -1};
        int dc[] = {1, 0, -1, 0, 1, -1, 1, -1};

        while (!pq.empty()) {

            auto [dist, coord] = pq.top();
            auto [x, y] = coord;
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int r = x + dr[i];
                int c = y + dc[i];

                if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 0) {
                    if (dist + 1 < distance[r][c]) {
                        distance[r][c] = dist + 1;
                        pq.push({dist + 1, {r, c}});
                    }
                }
            }
        }

        return -1;
    }
};
