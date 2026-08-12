class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);

        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        int ans = 0;
        int rightMax = 0;

        for (int i = n - 1; i >= 0; i--) {

            rightMax = max(rightMax, height[i]);

            ans += min(leftMax[i], rightMax) - height[i];
        }

        return ans;
    }
};