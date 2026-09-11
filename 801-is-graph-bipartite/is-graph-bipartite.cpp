class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) {
                continue;
            }
            queue<int> q;
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto nei : graph[node]) {
                    if (color[nei] == -1) {

                        color[nei] = 1 - color[node];

                        q.push(nei);
                    } else if (color[nei] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};