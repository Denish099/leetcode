class Solution {
public:
    vector<int> dp;

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();

        dp.resize(n, -1);

        auto helper = [&](auto&& self, int idx) -> int {
            if (idx == n) {
                return 0;
            }

            if (dp[idx] != -1) {
                return dp[idx];
            }

            int width = 0;
            int height = 0;

            int ans = INT_MAX;

            for (int i = idx; i < n; i++) {

                width += books[i][0];

                if (width > shelfWidth) {
                    break;
                }

                height = max(height, books[i][1]);

                ans = min(ans, height + self(self, i + 1));
            }

            return dp[idx] = ans;
        };

        return helper(helper, 0);
    }
};