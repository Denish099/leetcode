class Solution {
public:
    int n, m;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<int>>& visited) {

        visited[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                board[nr][nc] == 'O' && visited[nr][nc] == 0) {
                dfs(nr, nc, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0)
                dfs(i, 0, board, visited);

            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0)
                dfs(i, m - 1, board, visited);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && visited[0][j] == 0)
                dfs(0, j, board, visited);

            if (board[n - 1][j] == 'O' && visited[n - 1][j] == 0)
                dfs(n - 1, j, board, visited);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};
