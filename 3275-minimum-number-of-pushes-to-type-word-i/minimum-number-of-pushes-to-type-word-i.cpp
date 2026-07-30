class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (i < 8) {
                ans += 1;
            } else if (i <= 15) {
                ans += 2;
            } else if (i <= 23) {
                ans += 3;

            } else {
                ans += 4;
            }
        }

        return ans;
    }
};