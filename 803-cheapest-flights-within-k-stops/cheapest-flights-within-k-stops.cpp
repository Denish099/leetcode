class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>>
            pq;

        pq.push({0, {src, 0}});

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int node = top.second.first;
            int stops = top.second.second;

            if (node == dst)
                return cost;

            if (stops > k)
                continue;

            for (auto &neighbour : adj[node]) {
                int nextNode = neighbour.first;
                int price = neighbour.second;

                if (cost + price < dist[nextNode][stops + 1]) {
                    dist[nextNode][stops + 1] = cost + price;
                    pq.push({cost + price, {nextNode, stops + 1}});
                }
            }
        }

        return -1;
    }
};
