class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        int size = beginWord.size();

        if (!st.count(endWord)) {
            return 0;
        }

        set<string> vis;
        vis.insert(beginWord);

        queue<string> q;
        q.push(beginWord);

        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) {
                    return level + 1;
                }

                for (int i = 0; i < size; i++) {

                    char original = curr[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) {
                            continue;
                        }

                        curr[i] = c;
                        if (!vis.count(curr) && st.count(curr)) {
                            q.push(curr);
                            vis.insert(curr);
                        }

                        curr[i] = original;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};