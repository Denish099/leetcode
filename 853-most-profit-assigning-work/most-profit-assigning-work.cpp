class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<vector<int>> arr;
        int n = difficulty.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({difficulty[i], profit[i]});
        }

        // Sort by difficulty
        sort(arr.begin(), arr.end());

        // Prefix maximum profit
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, arr[i][1]);
            arr[i][1] = mx;
        }

        int ans = 0;

        for (int w : worker) {
            int l = 0, r = n;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (arr[mid][0] <= w)
                    l = mid + 1;
                else
                    r = mid;
            }

            if (l > 0)
                ans += arr[l - 1][1];
        }

        return ans;
    }
};