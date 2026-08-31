class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i = 0;i<n;i++){
            int x = abs(nums[i]);

            if(nums[x] < 0){
                return ans = x;
            }else{
                nums[x] *= -1;
            }
        }

        return ans;
    }
};