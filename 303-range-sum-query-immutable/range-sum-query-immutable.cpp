class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);

        if (n > 0) {
            prefixSum[0] = nums[0];
        }

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left != 0) {
            return prefixSum[right] - prefixSum[left - 1];
        } else {
            return prefixSum[right];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */