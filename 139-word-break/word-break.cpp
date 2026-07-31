class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            for (int j = n - 1; j >= i; j--) {
                if (st.find(s.substr(i, j - i + 1)) != st.end() && dp[i]) {
                    dp[j+1] = true;
                }
            }
        }

        return dp[n];
    }
};