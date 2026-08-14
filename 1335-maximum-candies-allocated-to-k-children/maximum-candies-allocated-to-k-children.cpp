class Solution {
public:
    bool helper(long long mid, vector<int>& nums, long long k) {

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {

            
                ans += (nums[i] / mid); // nums[i] == 10 , mid == 5
            
        }

        if (ans >= k) {
            return true;
        }

        return false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        long long start = 1;
        long long end = *max_element(nums.begin(), nums.end());

        cout << end;

        long long ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2; // 6
            if (helper(mid, nums, k)) {
                start = mid + 1; // 5
                ans = mid;

            } else {
                end = mid - 1; // 17 -> 8
            }
        }

        return (int)ans;
    }
};