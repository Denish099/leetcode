class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int count = 0;

        auto dfs = [&](auto&& self,int node, int parent) -> void {
            for (auto& p : adj[node]) {
                int v = p.first;

                if (v != parent) {
                    if (p.second == 1) {
                        count++;
                    }
                    self(self,v,node);
                }
            }
        };

        dfs(dfs,0,-1);
        return count;
    }
};