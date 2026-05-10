class Solution {
public:
    vector<int> dp;
    
    int helper(vector<int>& nums, int target, int i) {
        if (i == nums.size() - 1) return 0;
        
        // Check against -2 now!
        if (dp[i] != -2) {
            return dp[i];
        }

        int max_jumps = -1; 
        for (int j = i + 1; j < nums.size(); j++) {
            // Using long long to safely prevent integer overflow on massive numbers
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
        
        // Initialize with -2 (uncalculated)
        dp.assign(n, -2); 
        
        return helper(nums, target, 0);
    }
};