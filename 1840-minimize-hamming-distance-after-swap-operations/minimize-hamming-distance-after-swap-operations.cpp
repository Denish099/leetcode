#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]); 
    }

    void unite(vector<int>& parent, int i, int j) {
        int rootI = find(parent, i);
        int rootJ = find(parent, j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); 

        for (const auto& swap : allowedSwaps) {
            unite(parent, swap[0], swap[1]);
        }

        unordered_map<int, unordered_map<int, int>> componentPool;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            componentPool[root][source[i]]++;
        }

        
        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            int targetVal = target[i];

            if (componentPool[root][targetVal] > 0) {
                componentPool[root][targetVal]--;
            } else {
                
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};