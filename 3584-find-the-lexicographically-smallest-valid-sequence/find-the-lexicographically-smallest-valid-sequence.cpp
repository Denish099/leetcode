class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        vector<int> last(n2, -1);
        for (int i = n2 - 1, j = n1 - 1; i >= 0; i--) {
            while (j >= 0 && word1[j] != word2[i]) {
                j--;
            }
            last[i] = j;
            if (j >= 0) {
                j--;
            }
        }

        vector<int> result;
        bool changed = false;
        int j = 0;

        for (int i = 0; i < n2; i++) {
            while (j < n1) {
                bool is_match = (word1[j] == word2[i]);
                bool can_finish_suffix =
                    (i + 1 == n2) || (j + 1 <= last[i + 1]);

                if (is_match) {

                    result.push_back(j);
                    j++;
                    break;

                } else {
                    if (!changed && can_finish_suffix) {
                        changed = true;
                        result.push_back(j);
                        j++;
                        break;
                    }
                }
                j++;
            }

            if (result.size() != i + 1) {
                return {};
            }
        }

        return result;
    }
};
