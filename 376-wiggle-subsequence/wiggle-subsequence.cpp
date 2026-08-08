class Solution {
public:
    int solve(int i, int prev, int sign,
              vector<int>& nums,
              vector<vector<vector<int>>>& dp) {

        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1][sign + 1] != -1)
            return dp[i][prev + 1][sign + 1];

        int ans = solve(i + 1, prev, sign, nums, dp);

        if (prev == -1) {
            ans = max(ans, 1 + solve(i + 1, i, 0, nums, dp));
        }
        else {
            int diff = nums[i] - nums[prev];

            if (sign == 0 && diff != 0) {
                int nextSign = (diff > 0) ? -1 : 1;

                ans = max(ans,
                          1 + solve(i + 1, i, nextSign, nums, dp));
            }

            else if (sign == 1 && diff > 0) {
                ans = max(ans,
                          1 + solve(i + 1, i, -1, nums, dp));
            }

            else if (sign == -1 && diff < 0) {
                ans = max(ans,
                          1 + solve(i + 1, i, 1, nums, dp));
            }
        }

        return dp[i][prev + 1][sign + 1] = ans;
    }

    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();

     
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
                vector<int>(3, -1))
        );

        return solve(0, -1, 0, nums, dp);
    }
};