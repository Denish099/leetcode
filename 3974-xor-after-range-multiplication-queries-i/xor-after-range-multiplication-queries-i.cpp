class Solution {
public:
    int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q: queries){
            int idx = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for(int i = idx;i<=r;i+=k){
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        int x = 0;
        for(int i = 0;i<nums.size();i++){
            x ^= nums[i];
        }

        return x;
    }
};