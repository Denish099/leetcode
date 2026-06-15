class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int helper(int i, int j, vector<vector<int>>& obs) {

        if (i >= m || j >= n) {
            return 0;
        }
        if (obs[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        return dp[i][j] = helper(i + 1, j, obs) + helper(i, j + 1, obs);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        m = obs.size();
        n = obs[0].size();

        dp.resize(m+1,vector<int>(n+1,-1));

        return helper(0, 0, obs);
    }
};