class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int len = 1;

        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        for (int l = 2; l <= n; l++) {

            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                if (s[i] != s[j])
                    dp[i][j] = false;

                else {

                    if (l == 2)
                        dp[i][j] = true;

                    else
                        dp[i][j] = dp[i + 1][j - 1];

                    if (dp[i][j] && l > len) {
                        len = l;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};