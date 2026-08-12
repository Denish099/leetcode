class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        int mul = 1;
        for (int i = 0; i < n; i++) {
            mul *= nums[i];
            prefix[i] = mul;
        }

        mul = 1;
        for (int i = n - 1; i >= 0; i--) {
            mul *= nums[i];
            suffix[i] = mul;
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 && i < n - 1) {
                ans[i] = prefix[i - 1] * suffix[i + 1];
            } else if (i < 1) {
                ans[i] = suffix[i + 1];
            } else {
                ans[i] = prefix[i - 1];
            }
        }

        return ans;
    }
};