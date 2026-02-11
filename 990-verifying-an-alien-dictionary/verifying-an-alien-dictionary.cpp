class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Map each character to its alien rank
        vector<int> rank(26);
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Step 2: Compare adjacent words
        for (int i = 1; i < words.size(); i++) {
            string &w1 = words[i - 1];
            string &w2 = words[i];
            
            int j = 0;
            int len = min(w1.size(), w2.size());

            // Compare characters
            while (j < len) {
                if (w1[j] != w2[j]) {
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a'])
                        return false;
                    break;
                }
                j++;
            }

            // Prefix case: "apple" before "app" → invalid
            if (j == len && w1.size() > w2.size())
                return false;
        }

        return true;
    }
};
