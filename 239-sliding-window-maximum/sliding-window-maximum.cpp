
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();

        vector<int> ans;

        // Store indices, not values
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) {

            // Remove elements that are outside the window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from the back
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
