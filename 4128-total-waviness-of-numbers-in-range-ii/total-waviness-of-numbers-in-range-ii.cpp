class Solution {
   
    pair<long long, long long> memo[20][11][11];

    pair<long long, long long> dfs(int idx, int prev_digit, int last_digit, bool is_limit, const string& s) {
       
        if (idx == s.size()) {
            return {1, 0}; 
        }

        if (!is_limit && memo[idx][prev_digit][last_digit].first != -1) {
            return memo[idx][prev_digit][last_digit];
        }

        long long count = 0;
        long long waviness = 0;
        
        int upper = is_limit ? s[idx] - '0' : 9;

        for (int d = 0; d <= upper; d++) {
            int next_prev, next_last;
            
            if (last_digit == 10) { 
                if (d == 0) {
                    next_prev = 10;
                    next_last = 10;
                } else {
                    next_prev = 10;
                    next_last = d;
                }
            } else {
                next_prev = last_digit;
                next_last = d;
            }

            auto res = dfs(idx + 1, next_prev, next_last, is_limit && (d == upper), s);
            
            count += res.first;
            waviness += res.second;

            if (last_digit != 10 && prev_digit != 10) {
                bool is_peak = (last_digit > prev_digit && last_digit > d);
                bool is_valley = (last_digit < prev_digit && last_digit < d);
                
                if (is_peak || is_valley) {
                   
                    waviness += res.first;
                }
            }
        }

        if (!is_limit) {
            memo[idx][prev_digit][last_digit] = {count, waviness};
        }

        return {count, waviness};
    }

    long long solve(long long num) {
        if (num < 0) return 0;
        string s = to_string(num);
        
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 11; j++) {
                for (int k = 0; k < 11; k++) {
                    memo[i][j][k] = {-1, -1};
                }
            }
        }
        
        return dfs(0, 10, 10, true, s).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};