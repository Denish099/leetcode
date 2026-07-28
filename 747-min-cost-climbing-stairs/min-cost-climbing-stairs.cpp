class Solution {
public:
    vector<int> dp;
    
    int helper(int idx, vector<int>& cost) {
        // Base case: if we reach or pass the top floor, no more cost is needed.
        if (idx >= cost.size()) {
            return 0;
        }
        
        // Return the already computed result to avoid recomputing overlapping subproblems.
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        // Pay the cost at the current step, then take the minimum of a 1-step or 2-step jump.
        return dp[idx] = cost[idx] + min(helper(idx + 1, cost), helper(idx + 2, cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1); // We only need size 'n' because valid indices are 0 to n-1
        
        // We can start from either index 0 or index 1
        return min(helper(0, cost), helper(1, cost));
    }
};