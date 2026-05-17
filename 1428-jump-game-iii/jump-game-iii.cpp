class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);

        vector<int> vis(n,0);

            while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (arr[idx] == 0) {
                return true;
            }

            if (idx + arr[idx] < arr.size() && vis[idx + arr[idx]] == 0) {
                q.push(idx + arr[idx]);
            }

            if (idx - arr[idx] >= 0 && vis[idx - arr[idx]] == 0) {
                q.push(idx - arr[idx]);
            }

            vis[idx] = 1;
        }

        return false;
    }
};