class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findRoot(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findRoot(parent[node]);
    }

    void unionByRank(int u, int v) {
        int rootU = findRoot(u);
        int rootV = findRoot(v);

        if (rootU == rootV)
            return;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } 
        else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } 
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if (connections.size() < n - 1)
            return -1;
        
        DisjointSet ds(n);
        
        for (auto &connection : connections) {
            ds.unionByRank(connection[0], connection[1]);
        }
        
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findRoot(i) == i)
                components++;
        }
        
        return components - 1;
    }
};