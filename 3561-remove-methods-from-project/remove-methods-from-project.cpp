class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);

        for (auto &e : nums) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> bad(n, false);
        queue<int> q;

        q.push(k);
        bad[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!bad[v]) {
                    bad[v] = true;
                    q.push(v);
                }
            }
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (bad[i] || vis[i]) continue;

            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (bad[v]) {
                        vector<int> ans;
                        for (int j = 0; j < n; j++)
                            ans.push_back(j);
                        return ans;
                    }

                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!bad[i]) ans.push_back(i);
        }

        return ans;
    }
};