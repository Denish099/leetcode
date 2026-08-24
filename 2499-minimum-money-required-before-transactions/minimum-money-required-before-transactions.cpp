class Solution {
public:
    long long minimumMoney(vector<vector<int>>& c) {
        int n = c.size();

        vector<vector<int>> higher;
        vector<vector<int>> lower;

        long long loss = 0;
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            if (c[i][0] > c[i][1]) {
                lower.push_back(c[i]);
                loss += c[i][0] - c[i][1];
            } else {
                higher.push_back(c[i]);
            }

            mx = max(mx, (long long)min(c[i][0], c[i][1]));
        }

        sort(lower.begin(), lower.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        sort(higher.begin(), higher.end(),
             [](auto& a, auto& b) {
                 return a[0] > b[0];
             });

        return loss + mx;
    }
};