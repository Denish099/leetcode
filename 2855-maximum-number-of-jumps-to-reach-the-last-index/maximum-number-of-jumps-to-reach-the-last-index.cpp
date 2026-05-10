class Solution {
public:
    vector<int> dp;
    
    int helper(vector<int>& nums, int target, int i) {
        if (i == nums.size() - 1) return 0;
        
        if (dp[i] != -2) {
            return dp[i];
        }

        int max_jumps = -1; 
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs((long long)nums[j] - nums[i]) <= target) {
                int jumps_from_j = helper(nums, target, j);
                if (jumps_from_j != -1) {
                    max_jumps = max(max_jumps, 1 + jumps_from_j);
                }
            }
        }
        
        return dp[i] = max_jumps;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        dp.assign(n, -2); 
        
        return helper(nums, target, 0);
    }
};