class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        
        unordered_map<int, vector<long long>> mp;

        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }

        for (auto& [val, indices] : mp) {
            long long totalSum = 0;
            for (long long idx : indices) {
                totalSum += idx;
            }

            long long leftSum = 0;
            long long m = indices.size();

            for (int i = 0; i < m; ++i) {
                long long idx = indices[i];
                
               
                long long rightSum = totalSum - leftSum - idx;

                long long leftDist = (i * idx) - leftSum;
                long long rightDist = rightSum - ((m - 1 - i) * idx);

                ans[idx] = leftDist + rightDist;

                leftSum += idx;
            }
        }

        return ans;
    }
};