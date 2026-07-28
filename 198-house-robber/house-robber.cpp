class Solution {
public:
    vector<int> dp;
    // int helper(vector<int>& nums,int idx,int total){
    //     if(idx >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }

    //     return dp[idx] = max(nums[idx] + helper(nums,idx+2,total),helper(nums,idx+1,total));
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2,-1);
        dp[n] = 0;
        dp[n+1] = 0;
        for(int i = n-1;i>=0;i--){
            dp[i] = max(nums[i] + dp[i+2],dp[i+1]);
        }

        return dp[0];
    }
};