class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 1;

        for (int x : st) {

            if (st.find(x - 1) == st.end()) {

                int len = 1;
                int curr = x;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};