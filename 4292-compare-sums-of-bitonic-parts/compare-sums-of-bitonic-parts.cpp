class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        long long lSum = 0;
        long long rSum = 0;

        int flag = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                flag = true;
                lSum += nums[i];
            }

            if (!flag) {
                lSum += nums[i];
            }

            if (flag) {
                rSum += nums[i];
            }
        }


        if(lSum == rSum){
            return -1;
        }else if(lSum > rSum){
            return 0;
        }

        return 1;
    }
};