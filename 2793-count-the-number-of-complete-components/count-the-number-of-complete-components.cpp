class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    bool bfs(int node) {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        int nodes = 0;
        int edges = 0;

        while (!q.empty()) {
            int val = q.front();
            q.pop();

            nodes++;
            edges += adj[val].size();

            for (int nei : adj[val]) {
                if (!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }

        edges /= 2;

        return edges == nodes * (nodes - 1) / 2;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;

        adj.resize(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis.resize(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (bfs(i)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};