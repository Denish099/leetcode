class Solution {
public:
    int nc2(int n) {
        return n * (n - 1) / 2;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        vector<int> diff;
        for (int i = 0; i < nums.size() - 1; i++) {
            diff.push_back(nums[i + 1] - nums[i]);
        }

        int ans = 0;

        for (int i = 0; i < diff.size(); i++) {
            int k = i + 1;

            while (k < diff.size() && diff[k] == diff[i]) {
                k++;
            }

            int len = k - i;     

            if (len >= 2)
                ans += nc2(len);

            i = k - 1;
        }

        return ans;
    }
};