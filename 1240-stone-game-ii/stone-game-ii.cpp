class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int helper(int M, int idx, vector<int>& piles) {
        if (idx >= n) {
            return 0;
        }

        if(dp[idx][M] != -1){
            return dp[idx][M];
        }

        int res = INT_MAX;

        for (int x = 1; x <= 2 * M; x++) {
            res = min(res, helper(max(M, x), idx + x, piles));
        }

        return dp[idx][M] = piles[idx] - res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        for(int i = n-2;i>=0;i--){
            piles[i] += piles[i+1];
        }
        return helper(1,0,piles);
    }
};