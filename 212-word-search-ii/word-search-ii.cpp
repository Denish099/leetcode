class Solution {
public:

    static const int MAXN = 30005;

    static int ch[MAXN][26];
    static bool isEnd[MAXN];
    static string word[MAXN];
    static int sz;

    void insert(string s) {

        int curr = 0;

        for (char c : s) {

            int x = c - 'a';

            if (ch[curr][x] == 0) {
                ch[curr][x] = sz++;
            }

            curr = ch[curr][x];
        }

        isEnd[curr] = true;
        word[curr] = s;
    }

    void dfs(
        int i,
        int j,
        vector<vector<char>>& board,
        vector<vector<int>>& vis,
        int node,
        vector<string>& ans
    ) {

        int x = board[i][j] - 'a';

        if (ch[node][x] == 0) {
            return;
        }

        int nextNode = ch[node][x];

        if (isEnd[nextNode]) {

            ans.push_back(word[nextNode]);

   
            isEnd[nextNode] = false;
        }

        vis[i][j] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || ni >= board.size() ||
                nj < 0 || nj >= board[0].size()) {
                continue;
            }

            if (vis[ni][nj]) {
                continue;
            }

            dfs(
                ni,
                nj,
                board,
                vis,
                nextNode,
                ans
            );
        }

        vis[i][j] = 0;
    }

    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words
    ) {


        sz = 1;


        memset(ch, 0, sizeof(ch));
        memset(isEnd, 0, sizeof(isEnd));

        for (string& s : words) {
            insert(s);
        }

        int m = board.size();
        int n = board[0].size();

        vector<string> ans;

        vector<vector<int>> vis(
            m,
            vector<int>(n, 0)
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                dfs(
                    i,
                    j,
                    board,
                    vis,
                    0,
                    ans
                );
            }
        }

        return ans;
    }
};


int Solution::ch[Solution::MAXN][26];
bool Solution::isEnd[Solution::MAXN];
string Solution::word[Solution::MAXN];
int Solution::sz = 1;