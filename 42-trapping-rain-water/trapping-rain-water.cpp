class Solution {
public:
    int trap(vector<int>& nums) {
        int n =  nums.size();

        vector<int> leftMax(n,0);
        leftMax[0] = nums[0];

        for(int i = 1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],nums[i]);
        }

        int rightMax = 0;
        int ans = 0;

        for(int i = n-1;i>=0;i--){
            rightMax= max(rightMax,nums[i]);

            ans += min(leftMax[i],rightMax) - nums[i];
        }

        return ans;

    }
};