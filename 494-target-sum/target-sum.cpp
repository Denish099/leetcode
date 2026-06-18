class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int helper(vector<int>& nums, int idx, int sum, int target) {
        if (idx == n)
            return sum == target;

        if (dp[idx][sum + 1000] != -1)
            return dp[idx][sum + 1000];

        int add = helper(nums, idx + 1, sum + nums[idx], target);
        int sub = helper(nums, idx + 1, sum - nums[idx], target);

        return dp[idx][sum + 1000] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total)
            return 0;

        dp.assign(n, vector<int>(2001, -1));

        return helper(nums, 0, 0, target);
    }
};