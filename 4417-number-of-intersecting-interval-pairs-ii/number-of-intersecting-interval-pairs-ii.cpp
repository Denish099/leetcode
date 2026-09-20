class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> starts, ends;

        for (auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int start = starts[i];

            int idx =
                lower_bound(ends.begin(), ends.end(), start) - ends.begin();

            ans += idx;
        }

        long long totalPairs = 1LL *  n * (n - 1) / 2;

        return totalPairs - ans;
    }
};