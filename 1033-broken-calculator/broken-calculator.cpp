class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // 3, 31
        // 3, 32
        // 3, 16
        // 3, 8
        // 3, 4
        // 3, 2
        // 3, 3

        int ans = 0;

        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
                ans++;
            } else {
                target += 1;
                ans++;
            }
        }

        return ans + (startValue - target);
    }
};