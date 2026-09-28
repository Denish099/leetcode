class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int sum = 0;
        for(int i = 0;i<nums.length;i++){
            if(i == 0){
                ans[i] = nums[i];
                continue;
            }
            ans[i] = ans[i-1] + nums[i];
        }

        return ans;
    }
}