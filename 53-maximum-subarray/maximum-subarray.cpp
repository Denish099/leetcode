class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        for(auto num:nums){
            if(sum < 0){
                sum = 0;
            }

            sum += num;
            ans = max(ans,sum);
        }

        return ans;
    }
};