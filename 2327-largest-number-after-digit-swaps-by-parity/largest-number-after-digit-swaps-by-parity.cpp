class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        vector<int> digits;

        int x = num;

        while (x > 0) {
            int digit = x % 10;
            digits.push_back(digit);
            x /= 10;

            if (digit % 2 == 0)
                even.push_back(digit);
            else
                odd.push_back(digit);
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int oi = 0, ei = 0;
        int ans = 0;

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] % 2 == 0)
                ans = ans * 10 + even[ei++];
            else
                ans = ans * 10 + odd[oi++];
        }

        return ans;
    }
};