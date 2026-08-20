class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int idx1 = 0;
        int idx2 = 0;

        int n = nums.size();
        if (n < 3) {
            return nums;
        }

        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            if(arr1[idx1] > arr2[idx2]){
                arr1.push_back(nums[i]);
                idx1++;
            }
            else{
                arr2.push_back(nums[i]);
                idx2++;
            }
        }

        arr1.insert(arr1.end(),arr2.begin(),arr2.end());

        return arr1;
    }
};