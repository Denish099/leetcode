class Solution {
public:

    struct DSU {
        vector<int> parent;
        vector<int> size;

        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x == parent[x]) {
                return x;
            }

            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b) {
                return false;
            }

            if (size[a] < size[b]) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];

            return true;
        }
    };


    vector<int> findRedundantDirectedConnection(
        vector<vector<int>>& edges
    ) {

        int n = edges.size();

        vector<int> parent(n + 1, 0);

        vector<int> candidate1;
        vector<int> candidate2;


        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (parent[v] == 0) {
                parent[v] = u;
            }
            else {

                candidate1 = {parent[v], v};
                candidate2 = {u, v};

                break;
            }
        }


        DSU dsu(n);

        for (auto& edge : edges) {


            if (!candidate2.empty() &&
                edge[0] == candidate2[0] &&
                edge[1] == candidate2[1]) {

                continue;
            }

            if (!dsu.unite(edge[0], edge[1])) {


                if (!candidate1.empty()) {
                    return candidate1;
                }

                return edge;
            }
        }


        return candidate2;
    }
};