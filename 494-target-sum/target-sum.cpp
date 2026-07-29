class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int> nums, int target, int idx, int sum) {

        if (sum == target && idx >= nums.size()) {
            return 1;
        }

        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx][sum + 1000] != -1) {
            return dp[idx][sum + 1000];
        }
        int add = helper(nums, target, idx + 1, sum + nums[idx]);
        int sub = helper(nums, target, idx + 1, sum - nums[idx]);

        return dp[idx][sum + 1000] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size(), vector<int>(2001, -1));

        return helper(nums, target, 0, 0);
    }
};