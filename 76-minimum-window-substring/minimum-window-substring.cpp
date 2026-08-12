class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) {
            return "";
        }
        int n = s.size();
        unordered_map<char, int> freq;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        int required = freq.size();
        int left = 0;
        int min_len = INT_MAX;
        int formed = 0;
        int start = 0;
        string ans;
        unordered_map<char, int> window;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (freq.count(ch)) {
                window[ch]++;
            }

            if (freq.count(s[i]) && freq[s[i]] == window[s[i]]) {
                formed++;
            }

            while (formed == required) {

                if (i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    start = left;
                }
                char c = s[left];
                window[c]--;

                if (freq.count(c) && freq[c] > window[c]) {
                    formed--;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};