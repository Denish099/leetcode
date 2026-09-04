class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[n] = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mp[i] = min(nums[i], mp[i + 1]);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int mini = mp[i];

            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};