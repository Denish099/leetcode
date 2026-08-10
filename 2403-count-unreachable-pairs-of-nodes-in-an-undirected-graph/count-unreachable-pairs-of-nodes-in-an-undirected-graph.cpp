class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto bfs = [&](int start) -> int {
            queue<int> q;
            q.push(start);
            vis[start] = true;

            int size = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                size++;

                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            return size;
        };

        long long ans = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                int size = bfs(i);

               
                ans += 1LL * size * (remaining - size);

                remaining -= size;
            }
        }

        return ans;
    }
};