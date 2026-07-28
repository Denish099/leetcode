class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sumMin = 0;
        int sumMax = 0;
        int totalMax = INT_MIN;
        int totalMin = INT_MAX;

        for (auto num : nums) {
            sumMax += num;
            sumMin += num;
            totalMax = max(sumMax, totalMax);
            totalMin = min(sumMin,totalMin);

            if(sumMax < 0){
                sumMax = 0;
            }
            if(sumMin > 0){
                sumMin = 0;
            }
        }

        return max(abs(totalMax),abs(totalMin));
    }
};