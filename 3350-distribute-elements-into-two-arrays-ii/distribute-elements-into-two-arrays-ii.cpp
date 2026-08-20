class Solution {
public:

    int upperBound(vector<int>& arr, int target) {

        int left = 0;
        int right = arr.size();

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1, arr2;
        vector<int> sorted1, sorted2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        sorted1.push_back(nums[0]);
        sorted2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {

            int greater1 =
                sorted1.size() - upperBound(sorted1, nums[i]);

            int greater2 =
                sorted2.size() - upperBound(sorted2, nums[i]);

            if (greater1 > greater2) {

                arr1.push_back(nums[i]);

                int pos = upperBound(sorted1, nums[i]);
                sorted1.insert(sorted1.begin() + pos, nums[i]);

            } 
            else if (greater2 > greater1) {

                arr2.push_back(nums[i]);

                int pos = upperBound(sorted2, nums[i]);
                sorted2.insert(sorted2.begin() + pos, nums[i]);

            } 
            else if (arr1.size() <= arr2.size()) {

                arr1.push_back(nums[i]);

                int pos = upperBound(sorted1, nums[i]);
                sorted1.insert(sorted1.begin() + pos, nums[i]);

            } 
            else {

                arr2.push_back(nums[i]);

                int pos = upperBound(sorted2, nums[i]);
                sorted2.insert(sorted2.begin() + pos, nums[i]);
            }
        }

        vector<int> result;

        for (int num : arr1)
            result.push_back(num);

        for (int num : arr2)
            result.push_back(num);

        return result;
    }
};