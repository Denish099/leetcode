class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        int cnt = 0;
        int maxDefense = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {

            if (nums[i][1] < maxDefense) {
                cnt++;
            }

            maxDefense = max(maxDefense, nums[i][1]);
        }

        return cnt;
    }
};