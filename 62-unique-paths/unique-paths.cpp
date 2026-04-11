class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& memo) {
        if (i >= m || j >= n) {
            return 0;
        }
        
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

       
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int moveDown = helper(i + 1, j, m, n, memo);
        int moveRight = helper(i, j + 1, m, n, memo);

        return memo[i][j] = moveDown + moveRight;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        
        return helper(0, 0, m, n, memo);
    }
};