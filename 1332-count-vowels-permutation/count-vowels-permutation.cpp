class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9 + 7;

        unordered_map<int, vector<int>> mp;
        mp['a'-'a'] = {'e'-'a'};
        mp['e'-'a'] = {'a'-'a', 'i'-'a'};
        mp['i'-'a'] = {'a'-'a', 'e'-'a', 'o'-'a', 'u'-'a'};
        mp['o'-'a'] = {'i'-'a', 'u'-'a'};
        mp['u'-'a'] = {'a'-'a'};

        vector<vector<int>> memo (26, vector<int> (n+1, -1));

        auto dfs = [&] (auto&& self, int curr, int remaining) -> int {
            if (remaining == 0) return 1;

            if (memo[curr][remaining] != -1) return memo[curr][remaining];

            int ways = 0;
            for (int next : mp[curr]) {
                ways = (ways + self(self, next, remaining-1)) % MOD;
            }

            return memo[curr][remaining] = ways;
        };

        int ans = 0;
        ans = (ans + dfs(dfs, 'a' - 'a', n - 1)) % MOD;
        ans = (ans + dfs(dfs, 'e' - 'a', n - 1)) % MOD;
        ans = (ans + dfs(dfs, 'i' - 'a', n - 1)) % MOD;
        ans = (ans + dfs(dfs, 'o' - 'a', n - 1)) % MOD;
        ans = (ans + dfs(dfs, 'u' - 'a', n - 1)) % MOD;

        return ans;
    }
};