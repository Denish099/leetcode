class Solution {
public:
    int findFirst(vector<int>& nums, int target){
        int l = -1, r = nums.size();

        while(r - l > 1){
            int m = (l + r) / 2;

            if(nums[m] < target){
                l = m;
            }else{
                r = m;
            }
        }

        return r;
    }

    int findLast(vector<int>& nums, int target){
        int l = -1, r = nums.size();

        while(r - l > 1){
            int m = (l + r) / 2;

            if(nums[m] <= target){
                l = m;
            }else{
                r = m;
            }
        }

        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);

        if(first == nums.size() || nums[first] != target){
            return {-1, -1};
        }

        int last = findLast(nums, target);

        return {first, last};
    }
};