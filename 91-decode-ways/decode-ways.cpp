class Solution {
public:
    int arr[101];
    int helper(string& s, int i) {
        if (i >= s.size()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }

        if (arr[i] != -1) {
            return arr[i];
        }

        int ways = helper(s, i + 1);

        if (i + 1 < s.size()) {
            string res = s.substr(i, 2);
            if (res >= "10" && res <= "26") {
                ways += helper(s, i + 2);
            }
        }

        return arr[i] = ways;
    }
    int numDecodings(string s) {
        memset(arr, -1, sizeof(arr));
        return helper(s, 0);
    }
};