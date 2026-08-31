class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans;

        int j = 0;

        for (int i = 1; i <= n; i++) {

            
            while (j < n && nums[j] < i) {
                j++;
            }

       
            if (j == n || nums[j] != i) {
                ans.push_back(i);
            }

           
            if (j < n && nums[j] == i) {
                j++;
            }
        }

        return ans;
    }
};