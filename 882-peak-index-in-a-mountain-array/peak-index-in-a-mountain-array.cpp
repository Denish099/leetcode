class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;

        while(right-left>1){
            int mid = left + (right - left)/2;
            if(mid > 0 && arr[mid] >= arr[mid - 1]){
                left = mid;
            }else{
                right = mid;
            }
        }

        return left;
    }
};