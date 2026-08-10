class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<vector<int>> ans;
        auto dfs = [&](auto&& self, int node, vector<int> arr) -> void {
            arr.push_back(node);
            if (node == n - 1) {
                ans.push_back(arr);
                return;
            }

            for (int i = 0; i < graph[node].size(); i++) {
                self(self, graph[node][i],arr);
            }
        };

        dfs(dfs,0,{});
        return ans;
    }
};