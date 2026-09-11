class Solution {
public:
    vector<int> mx = {1, 0, -1, 0};
    vector<int> my = {0, 1, 0, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int x, y;
        int totalKeys = 0;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    x = i;
                    y = j;
                }

                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int allKeys = (1 << totalKeys) - 1;


        queue<tuple<int, int, int>> q;

        q.push({x, y, 0});


        vector<vector<vector<bool>>> vis(
            m,
            vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false))
        );

        vis[x][y][0] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [i, j, keys] = q.front();
                q.pop();


                if (keys == allKeys) {
                    return steps;
                }

                for (int k = 0; k < 4; k++) {

                    int ni = i + mx[k];
                    int nj = j + my[k];

                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                        continue;
                    }

                    if (grid[ni][nj] == '#') {
                        continue;
                    }

                    int newKeys = keys;


                    if (grid[ni][nj] >= 'a' &&
                        grid[ni][nj] <= 'f') {

                        int key = grid[ni][nj] - 'a';

                        newKeys = keys | (1 << key);
                    }

      
                    if (grid[ni][nj] >= 'A' &&
                        grid[ni][nj] <= 'F') {

                        int key = grid[ni][nj] - 'A';


                        if ((keys & (1 << key)) == 0) {
                            continue;
                        }
                    }

                    if (vis[ni][nj][newKeys]) {
                        continue;
                    }

                    vis[ni][nj][newKeys] = true;

                    q.push({ni, nj, newKeys});
                }
            }

            steps++;
        }

        return -1;
    }
};