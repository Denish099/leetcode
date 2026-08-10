class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n + 1, false);

        auto dfs = [&](auto&& self, int node) -> void {
            vis[node] = true;
            auto next = rooms[node];
            for (int i = 0; i < next.size(); i++) {
                if (!vis[next[i]]) {
                    self(self, next[i]);
                }
            }
        };

        dfs(dfs, 0);

        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                flag = false;
            }
        }

        return flag;
    }
};