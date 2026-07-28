class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0;
        
        int curr_max = 0, max_sum = nums[0];
        int curr_min = 0, min_sum = nums[0];
        
        for (int num : nums) {
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
            
            total_sum += num;
        }
        
       
        if (max_sum < 0) {
            return max_sum;
        }
        
        return max(max_sum, total_sum - min_sum);
    }
};