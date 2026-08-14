class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);

        int idx = -1;

        // Find the last violation
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] > s[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            return n;
        }

        // Decrease the problematic digit
        s[idx]--;

        // Propagate the correction to the left
        while (idx > 0 && s[idx - 1] > s[idx]) {
            s[idx - 1]--;
            idx--;
        }

        // Everything after idx should be 9
        for (int i = idx + 1; i < s.size(); i++) {
            s[i] = '9';
        }

        return stoi(s);
    }
};