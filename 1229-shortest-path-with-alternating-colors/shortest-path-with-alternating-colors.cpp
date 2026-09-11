class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : redEdges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
        }

        for (auto &e : blueEdges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 1});
        }

        vector<int> ans(n, -1);

        vector<vector<bool>> vis(n, vector<bool>(2, false));

        queue<pair<int, int>> q;

 
        q.push({0, -1});

        ans[0] = 0;

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [node, lastColor] = q.front();
                q.pop();

                for (auto [next, color] : adj[node]) {

                    if (lastColor != -1 && color == lastColor) {
                        continue;
                    }

                    if (vis[next][color]) {
                        continue;
                    }

                    vis[next][color] = true;

                    if (ans[next] == -1) {
                        ans[next] = dist + 1;
                    }

                    q.push({next, color});
                }
            }

            dist++;
        }

        return ans;
    }
};