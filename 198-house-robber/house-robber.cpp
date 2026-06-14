class Solution {
public:
vector<int> dp;
    int helper(vector<int>& nums, int idx) {
    if (idx >= nums.size()) return 0;

    if(dp[idx] != -1){
        return dp[idx];
    }

    return dp[idx] = max(
        nums[idx] + helper(nums, idx + 2),
        helper(nums, idx + 1)
    );
}
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1,-1);
        return helper(nums,0);
        
    }
};