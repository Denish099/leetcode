class Solution {
public:
    int cnt = 0;
    int n;
    void helper(vector<int>& nums, int target, int idx) {
        if (idx >= n) {
            if (target == 0) {
                cnt++;
            }
            return;
        }

        helper(nums, target + nums[idx], idx + 1);
        helper(nums, target - nums[idx], idx + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        helper(nums, target, 0);
        return cnt;
    }
};