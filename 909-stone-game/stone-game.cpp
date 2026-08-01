class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int take_i =
            nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));
        int take_j =
            nums[j] + min(solve(nums, i, j - 2), solve(nums, i + 1, j - 1));

        return dp[i][j] =  max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(), piles.end(), 0);
        int n = piles.size();

        dp.resize(n + 1, vector<int>(n + 1, -1));

        int score1 = solve(piles, 0, n - 1);

        return score1 > total - score1;
    }
};