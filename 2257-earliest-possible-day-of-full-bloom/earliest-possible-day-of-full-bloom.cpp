class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> arr;
        int n = plantTime.size();
        for (int i = 0; i < n; i++) {
            arr.push_back({plantTime[i], growTime[i]});
        }

        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) { return a[1] > b[1]; });

        for (int i = 0; i < n; i++) {
            cout << arr[i][0] << " " << arr[i][1] << endl;
        }
        int currentTime = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            currentTime += arr[i][0];

            ans = max(ans,currentTime + arr[i][1]);
        }

        return ans;
    }
};