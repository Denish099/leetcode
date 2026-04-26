#include <vector>

using namespace std;

class Solution {
    int dRow[4] = {-1, 0, 1, 0};
    int dCol[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int r, int c, int parent_r, int parent_c, char targetChar) {
        
        visited[r][c] = true;
        
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4; ++i) {
            int next_r = r + dRow[i];
            int next_c = c + dCol[i];

           
            if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n 
                && grid[next_r][next_c] == targetChar) {
                
                if (visited[next_r][next_c]) {
                    
                    if (next_r != parent_r || next_c != parent_c) {
                        return true; 
                    }
                } else {
                   
                    if (dfs(grid, visited, next_r, next_c, r, c, targetChar)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};