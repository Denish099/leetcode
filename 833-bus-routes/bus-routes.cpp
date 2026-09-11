class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int n = routes.size();


        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }


        vector<bool> vis(n, false);

        queue<int> q;


        for (int route : mp[source]) {
            q.push(route);
            vis[route] = true;
        }

        int ans = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int route = q.front();
                q.pop();


                for (int stop : routes[route]) {


                    if (stop == target) {
                        return ans;
                    }

           
                    for (int nextRoute : mp[stop]) {
                        if (!vis[nextRoute]) {
                            vis[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};