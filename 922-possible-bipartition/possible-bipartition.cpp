class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);


        for (auto edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int start = 1; start <= n; start++) {

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

                    }
                    else if (color[nei] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};