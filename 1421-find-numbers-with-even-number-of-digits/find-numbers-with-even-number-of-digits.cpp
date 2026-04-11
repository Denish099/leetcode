class Solution {
public:
    int getLength(int n) {
        if (n == 0)
            return 1;
        return floor(log10(abs(n))) + 1;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (getLength(nums[i]) % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};