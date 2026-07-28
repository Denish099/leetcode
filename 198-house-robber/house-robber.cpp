class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums,int idx,int total){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        return dp[idx] = max(nums[idx] + helper(nums,idx+2,total),helper(nums,idx+1,total));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        return helper(nums,0,0);
    }
};