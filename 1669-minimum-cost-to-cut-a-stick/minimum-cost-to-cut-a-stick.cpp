class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& cuts, int i, int j) {

        if (i > j)
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = INT_MAX;

        for (int k = i; k <= j; k++) {

            int cost = cuts[j + 1] - cuts[i - 1];

            int total = cost + solve(cuts, i, k - 1) + solve(cuts, k + 1, j);

            res = min(res, total);
        }

        return dp[i][j] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int> c;
        c.push_back(0);
        for (int i = 0; i < cuts.size(); i++) {
            c.push_back(cuts[i]);
        }

        c.push_back(n);
        sort(c.begin(), c.end());

        int m = cuts.size();
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));

        auto helper =
            [&](auto&& self, vector<int>& cuts, int i, int j) -> int {
                if (i > j)
                    return 0;

                if (dp[i][j] != -1) {
                    return dp[i][j];
                }

                int res = INT_MAX;

                for (int k = i; k <= j; k++) {

                    int cost = cuts[j + 1] - cuts[i - 1];

                    int total =
                        cost + self(self,cuts, i, k - 1) + self(self,cuts, k + 1, j);

                    res = min(res, total);
                }

                return dp[i][j] = res;
            };

        return helper(helper,c, 1, m);
    }
};