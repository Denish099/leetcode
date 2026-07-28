class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int negPos = -1;
        int countNeg = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
               
                left = i + 1;
                negPos = -1;
                countNeg = 0;
                continue;
            }
            if (nums[i] < 0) {
                countNeg++;
                if(negPos == -1){
                    negPos = i;
                }
            }

            if (countNeg % 2 == 0){
                ans = max(ans,i - left + 1);
            }else{
                ans = max(ans,i - negPos);

            }
        }

        return ans;
    }
};