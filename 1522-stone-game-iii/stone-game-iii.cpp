class Solution {
public:
    int n;
    vector<int> dp;
    int helper(vector<int>& nums, int i) {
        if (i >= n) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int res = INT_MIN; 
        res = max(res, nums[i] - helper(nums, i + 1));
        if (i + 1 < n)
            res = max(res, nums[i] + nums[i + 1] - helper(nums, i + 2));
        if (i + 2 < n)
            res = max(res, nums[i] + nums[i + 1] + nums[i + 2] -
                               helper(nums, i + 3));

        return dp[i] = res;
    }
    string stoneGameIII(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+2,-1);
        int ans = helper(nums, 0);
        if (ans == 0) {
            return "Tie";
        }

        return ans > 0 ? "Alice" : "Bob";
    }
};