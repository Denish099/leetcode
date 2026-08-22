class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (n > m) return 0;

        const long long LIMIT = INT_MAX;

        vector<vector<long long>> dp(
            m + 1, vector<long long>(n + 1, 0)
        );

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

                    if (dp[i][j] > LIMIT)
                        dp[i][j] = LIMIT;
                } 
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};