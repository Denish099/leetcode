class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        int mini = INT_MAX;

        while(start <= end){
            int mid = (start+end)/2;

            if(nums[mid] >= nums[start]){
                mini = min(mini,nums[start]);
                start = mid + 1;
            }else{
                mini = min(mini,nums[mid]);
                end = mid - 1;
            }
        }

        return mini;
        
    }
};