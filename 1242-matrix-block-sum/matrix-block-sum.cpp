class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum[i][j] = mat[i][j];

                if (i > 0)
                    prefixSum[i][j] += prefixSum[i - 1][j];
                if (j > 0)
                    prefixSum[i][j] += prefixSum[i][j - 1];
                if (i > 0 && j > 0)
                    prefixSum[i][j] -= prefixSum[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);

                int sum = prefixSum[r2][c2];

                if (r1 > 0)
                    sum -= prefixSum[r1 - 1][c2];
                if (c1 > 0)
                    sum -= prefixSum[r2][c1 - 1];
                if (r1 > 0 && c1 > 0)
                    sum += prefixSum[r1 - 1][c1 - 1];

                ans[i][j] = sum;
            }
        }

        return ans;
    }
};