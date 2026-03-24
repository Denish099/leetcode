class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;

        for(int i = 0;i<nums.size();i++){
            if(ans == sum - ans - nums[i]){
                return i;
            }

            ans+= nums[i];
        }

        return -1;
        
    }
};