class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> mx = {1, 0, -1, 0};
        vector<int> my = {0, 1, 0, -1};

        unordered_map<int, int> size;

        auto bfs = [&](int i, int j, int id) {
            queue<pair<int, int>> q;
            q.push({i, j});

            grid[i][j] = id;

            int cnt = 0;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                cnt++;

                for (int k = 0; k < 4; k++) {
                    int nx = x + mx[k];
                    int ny = y + my[k];

                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == 1) {

                        grid[nx][ny] = id;
                        q.push({nx, ny});
                    }
                }
            }

            return cnt;
        };


        int id = 2;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    size[id] = bfs(i, j, id);
                    id++;
                }
            }
        }

        int ans = 0;

  
        for (auto &[id, sz] : size) {
            ans = max(ans, sz);
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] != 0)
                    continue;

                set<int> seen;

                for (int k = 0; k < 4; k++) {
                    int nx = i + mx[k];
                    int ny = j + my[k];

                    if (nx >= 0 && nx < m &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] >= 2) {

                        seen.insert(grid[nx][ny]);
                    }
                }

                int curr = 1;

                for (int islandId : seen) {
                    curr += size[islandId];
                }

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};