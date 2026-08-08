class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        auto dfs = [&](auto&& self, int node) -> void {
            vis[node] = true;

            for (int i = 0; i < adj[node].size(); i++) {
                int next = adj[node][i];

                if (!vis[next]) {
                    self(self, next);
                }
            }
        };

        dfs(dfs, source);

        return vis[destination];
    }
};