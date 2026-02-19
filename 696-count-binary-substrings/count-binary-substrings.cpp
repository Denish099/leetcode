class Solution {
public:
    int countBinarySubstrings(string s) {
        int size = s.length();
        int i = 0;
        int count = 0;

        while (i < size) {
            int j = i;
            int cnt1 = 0;
            int cnt2 = 0;

            char firstChar = s[i];
            while (j < size && s[j] == firstChar) {
                cnt1++;
                j++;
            }

            char secondChar = (firstChar == '0') ? '1' : '0';
            while (j < size && s[j] == secondChar) {
                cnt2++;
                j++;
            }

            count += min(cnt1, cnt2);

            i += cnt1;
        }

        return count;
    }
};
