class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());

        int pref = 0;
        int i = 0;

        int j = i + 1;

        while (j < n && nums[j] - 1 == nums[j - 1]) {
            pref += nums[j - 1];
            j++;
        }

        pref += nums[j - 1];

        while (true) {
            if (st.find(pref) == st.end()) {
                return pref;
            }
            pref++;
        }
    }
};