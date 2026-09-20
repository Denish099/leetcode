class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] >= start && intervals[j][0] <= end) {
                    ans++;
                }
            }
        }

        return ans;
    }
};