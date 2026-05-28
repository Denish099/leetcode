class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans = nums[0];

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == ans){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt < 0){
                ans = nums[i];
                cnt = 0;
            }
        }

        return ans;
        
    }
};