class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> list(n + 1);
        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            list[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto neighbour : list[node]) {
                int nextNode = neighbour.first;
                int nextdistance = neighbour.second;
                if (dist + nextdistance < distance[nextNode]) {
                    distance[nextNode] = dist + nextdistance;
                    pq.push({dist + nextdistance, nextNode});
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i < n + 1; i++) {
            maxi = max(maxi, distance[i]);
        }

        return maxi == INT_MAX ? -1 : maxi;
    }

};