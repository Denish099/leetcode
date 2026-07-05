class Solution {
public:
    void helper(vector<vector<int>>& adj, vector<int>& vis, int start) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < adj[x].size(); i++) {
                int neighbor = adj[x][i];
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                helper(adj, visited, i);
                count++;
            }
        }

        return count;
    }
};
