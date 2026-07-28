class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> usedWords;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }

        if (count + 1 != pattern.size()) {
            return false;
        }
        int left = 0;

        for (int i = 0; i < pattern.size(); i++) {
            string res = "";

            for (left; left < s.size(); left++) {
                if (s[left] == ' ') {
                    left++;
                    break;
                }
                res += s[left];
            }
            if (mp.find(pattern[i]) != mp.end()) {
                if (res != mp[pattern[i]]) {
                    return false;
                }
            } else {
                if (usedWords.find(res) != usedWords.end()) {
                    return false;
                }
                mp[pattern[i]] = res;
                usedWords.insert(res);
            }
        }

        return true;
    }
};