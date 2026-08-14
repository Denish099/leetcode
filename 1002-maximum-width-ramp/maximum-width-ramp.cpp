class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 0;
        suffix[n - 1] = n - 1;

        // prefix[i] = index of minimum element from 0 to i
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[prefix[i - 1]]) {
                prefix[i] = i;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        // suffix[i] = index of maximum element from i to n-1
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[suffix[i + 1]]) {
                suffix[i] = i;
            } else {
                suffix[i] = suffix[i + 1];
            }
        }

        // Find maximum width
        int i = 0, j = 0;

        while (i < n && j < n) {

            if (nums[prefix[i]] <= nums[suffix[j]]) {
                ans = max(ans, suffix[j] - prefix[i]);
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
};