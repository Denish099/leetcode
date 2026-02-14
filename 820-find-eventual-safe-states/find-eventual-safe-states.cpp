class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                rev[v].push_back(u);  
                indegree[u]++;        
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for (int prev : rev[node]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};
