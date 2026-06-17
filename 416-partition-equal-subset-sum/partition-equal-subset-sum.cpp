class Solution {
public:
    bool solve(int i, int target, vector<vector<int>>& dp, vector<int>& arr) {
        if (target == 0)
            return true;
        if (i == 0)
            return target == arr[0];
        if (dp[i][target] != -1)
            return dp[i][target];
        int nottake = solve(i - 1, target, dp, arr);
        int take = false;
        if (arr[i] <= target) {
            take = solve(i - 1, target - arr[i], dp, arr);
        }

        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, dp, nums);
    }
};