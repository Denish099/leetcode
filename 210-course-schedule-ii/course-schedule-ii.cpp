class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            list[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (auto& x : list[curr]) {
                inDegree[x]--;
                if (inDegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        bool flag = (ans.size() == numCourses);

        if (flag)
            return ans;
        return vector<int>();
    }
};