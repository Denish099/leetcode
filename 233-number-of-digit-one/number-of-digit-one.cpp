class Solution {
public:
    long long dp[11][2][11];

    long long helper(string &s, int idx, bool tight, int cnt1) {
        if (idx == s.size()) {
            return cnt1;
        }

        if (dp[idx][tight][cnt1] != -1)
            return dp[idx][tight][cnt1];

        int ub = tight ? s[idx] - '0' : 9;

        long long ans = 0;

        for (int dig = 0; dig <= ub; dig++) {
            ans += helper(
                s,
                idx + 1,
                tight && (dig == ub),
                cnt1 + (dig == 1)
            );
        }

        return dp[idx][tight][cnt1] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, true, 0);
    }
};