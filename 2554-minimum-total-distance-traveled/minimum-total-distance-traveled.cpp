class Solution {
public:
    typedef long long ll;

    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions,
             vector<vector<ll>>& memo) {

        if (ri >= robot.size()) return 0;

        if (fi >= positions.size()) return 1e15;

        if (memo[ri][fi] != -1) return memo[ri][fi];

        ll take = abs(robot[ri] - positions[fi]) +
                  solve(ri + 1, fi + 1, robot, positions, memo);

        ll skip = solve(ri, fi + 1, robot, positions, memo);

        return memo[ri][fi] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;

        for (auto &f : factory) {
            int pos = f[0], limit = f[1];
            while (limit--) positions.push_back(pos);
        }

        int m = robot.size(), n = positions.size();

        vector<vector<ll>> memo(m + 1, vector<ll>(n + 1, -1));

        return solve(0, 0, robot, positions, memo);
    }
};