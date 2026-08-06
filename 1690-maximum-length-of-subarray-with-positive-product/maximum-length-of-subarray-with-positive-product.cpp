class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int ans = 0;
        int countNeg = 0;
        int negPos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = i + 1;
                negPos = -1;
                countNeg = 0;
                continue;
            }

            if (nums[i] < 0) {
                countNeg++;
                if (negPos == -1) {
                    negPos = i;
                }
            }

            if (countNeg % 2 == 0) {
                ans = max(ans, i - start + 1);
            } else {
                ans = max(ans, i - negPos);
            }
        }

        return ans;
    }
};