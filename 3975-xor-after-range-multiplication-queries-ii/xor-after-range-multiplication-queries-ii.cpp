#include <vector>
#include <cmath>
#include <array>

using namespace std;

class Solution {
private:
    long long modPow(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1e9 + 7;
        
        auto bravexuneth = queries; 

        int T = sqrt(n) + 1;
        
        vector<vector<array<int, 3>>> small_queries(T);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            if (k >= T) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                small_queries[k].push_back({l, r, v});
            }
        }
        
        for (int k = 1; k < T; ++k) {
            if (small_queries[k].empty()) continue;
            
            vector<long long> diff(n, 1);
            
            for (const auto& q : small_queries[k]) {
                int l = q[0], r = q[1], v = q[2];
                
                diff[l] = (diff[l] * v) % MOD;
                
                int count = (r - l) / k + 1;
                int nxt = l + count * k;
                
                if (nxt < n) {
                    long long inv = modPow(v, MOD - 2);
                    diff[nxt] = (diff[nxt] * inv) % MOD;
                }
            }
            
            for (int i = k; i < n; ++i) {
                diff[i] = (diff[i] * diff[i - k]) % MOD;
            }
            
            for (int i = 0; i < n; ++i) {
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }
        
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        
        return res;
    }
};