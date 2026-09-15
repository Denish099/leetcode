class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            vector<int> res(grid[i].begin(), grid[i].end());

            int k = rowShift[i];

            reverse(res.begin(), res.begin() + k);
            reverse(res.begin() + k, res.end());
            reverse(res.begin(), res.end());

            grid[i] = res;
        }

        for (int i = 0; i < n; i++) {
            vector<int> res;
            for (int j = 0; j < n; j++) {
                res.push_back(grid[j][i]);
            }


            int k = colShift[i];

            reverse(res.begin(), res.begin() + k);
            reverse(res.begin() + k, res.end());
            reverse(res.begin(), res.end());

            for (int j = 0; j < n; j++) {
                grid[j][i] = res[j];
            }
        }

        return grid;
    }
};