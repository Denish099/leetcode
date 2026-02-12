class Solution {
public:
    int longestBalanced(string s) {

        int mmax = INT_MIN;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            for (int j = i; j < n; j++) {
                mp[s[j] - 'a']++;
                bool flag = false;
                int current = mp[s[j] - 'a'];
                for (int k = 0; k < 26; k++) {
                    if (mp[k] == 0) {
                        continue;
                    }
                    if (mp[k] == current) {
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    mmax = max(j - i + 1, mmax);
                }
            }
        }

        return mmax;
    }
};