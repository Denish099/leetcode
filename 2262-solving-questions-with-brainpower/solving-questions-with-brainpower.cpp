class Solution {
public:
    int n;
    vector<long long> dp;
    long long helper(vector<vector<int>>& nums, int i) {
        if (i >= n) {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        return dp[i] =  max(nums[i][0] + helper(nums, i + nums[i][1] + 1),
                   helper(nums, i + 1));
    }
    long long mostPoints(vector<vector<int>>& nums) {
        n = nums.size();
        dp.resize(n+1,-1);

        return helper(nums, 0);
    }
};