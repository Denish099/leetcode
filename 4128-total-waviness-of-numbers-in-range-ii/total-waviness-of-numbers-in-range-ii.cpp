class Solution {
public:
    typedef long long ll;
    string s;
    int n;

    // Increased size to 20 to safely handle long long limits (up to 19 digits)
    ll dpTotalNumbers[20][10][10];
    ll dptotalWaviness[20][10][10];

    pair<ll, ll> solve(int curr, int pprev, int prev, bool tight, bool ldz) {
        if (curr == n) {
            return {1, 0};
        }

        // Use remaining length for the DP state to prevent leakage between func() calls
        int rem = n - curr;

        if (!tight && !ldz && prev != -1 && pprev != -1) {
            if (dpTotalNumbers[rem][pprev][prev] != -1) {
                return {dpTotalNumbers[rem][pprev][prev],
                        dptotalWaviness[rem][pprev][prev]};
            }
        }
        
        ll totalNumber = 0;
        ll totalWaviness = 0;

        int ub = tight ? (s[curr] - '0') : 9;

        for (int dig = 0; dig <= ub; dig++) {

            bool newTight = (tight && dig == ub);
            bool newLdz = (ldz && dig == 0);

            int newPrev = newLdz ? -1 : dig;
            int newPrevPrev = newLdz ? -1 : prev;

            auto [cnt, wav] =
                solve(curr + 1, newPrevPrev, newPrev, newTight, newLdz);

            if (!ldz && pprev != -1 && prev != -1) {
                bool isPeak = (pprev < prev && prev > dig);
                bool isValley = (pprev > prev && prev < dig);

                if (isPeak || isValley) {
                    totalWaviness += cnt;
                }
            }

            totalNumber += cnt;
            totalWaviness += wav;
        }
        
        if (!tight && !ldz && prev != -1 && pprev != -1) {
            dpTotalNumbers[rem][pprev][prev] = totalNumber;
            dptotalWaviness[rem][pprev][prev] = totalWaviness;
        }

        return {totalNumber, totalWaviness};
    }

    ll func(ll num) {
        if (num < 100)
            return 0;

        s = to_string(num);
        n = s.size();

        return solve(0, -1, -1, true, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dptotalWaviness, 0, sizeof(dptotalWaviness)); 
        
        return func(num2) - func(num1 - 1);
    }
};