class Solution {
    int getDistance(int a, int b) {
        if (a == 26)
            return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int solve(int i, int other_finger, const string& word,
              vector<vector<int>>& memo) {
        if (i == word.length())
            return 0;

        if (memo[i][other_finger] != -1)
            return memo[i][other_finger];

        int curr = word[i] - 'A';
        int prev = (i == 0) ? 26 : (word[i - 1] - 'A');

        int cost1 =
            getDistance(prev, curr) + solve(i + 1, other_finger, word, memo);

        int cost2 =
            getDistance(other_finger, curr) + solve(i + 1, prev, word, memo);

        return memo[i][other_finger] = min(cost1, cost2);
    }

public:
    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<int>> memo(n, vector<int>(27, -1));

        return solve(0, 26, word, memo);
    }
};