class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int currMinSum = 0;
        int currMaxSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        bool flag = false;

        for (auto num : nums) {
            if(num > 0){
                flag = true;
            }
            totalSum += num;
            currMinSum += num;
            currMaxSum += num;

            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);

            if (currMinSum > 0) {
                currMinSum = 0;
            }
            if (currMaxSum < 0) {
                currMaxSum = 0;
            }
        }

        if(totalSum < 0 && !flag){
            return maxSum;
        }

        return max(maxSum,totalSum - minSum);
    }
};