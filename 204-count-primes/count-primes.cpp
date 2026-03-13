class Solution {
public:
    int prime(int n) {
        vector<bool> primes(n + 1, true);

        int cnt = 0;

        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                cnt++;
                for (int j = i * 2; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        return cnt;
    }

    int countPrimes(int n) {
        return prime(n);
    }
};