class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());
        int count = 0;

        for(int i = 0; i < arr1.size(); i++) {

            int start = 0, end = arr2.size() - 1;
            bool found = false;

            while(start <= end) {
                int mid = (start + end) / 2;

                if(abs(arr1[i] - arr2[mid]) <= d) {
                    found = true;
                    break;
                }
                else if(arr2[mid] < arr1[i]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }

            if(!found) count++;
        }

        return count;
    }
};