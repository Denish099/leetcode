class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            if (mp.find(k) != mp.end()) {
                ans.push_back(mp[k]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};
