class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> expectedMatch;
        int min_dist = 1e9;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];

           
            if (expectedMatch.count(val)) {
                min_dist = min(min_dist, i - expectedMatch[val]);
            }

           
            int rev_val = reverseNumber(val);

           
            expectedMatch[rev_val] = i;
        }

        return min_dist == 1e9 ? -1 : min_dist;
    }
};