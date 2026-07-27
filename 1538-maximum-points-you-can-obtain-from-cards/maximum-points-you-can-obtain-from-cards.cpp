class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> res;
        int n = cardPoints.size();
        
        for(int i = n - k; i < n; i++) {
            res.push_back(cardPoints[i]);
        }
        for(int i = 0; i < k; i++) {
            res.push_back(cardPoints[i]);
        }

        int currSum = 0;
        for(int i = 0; i < k; i++) {
            currSum += res[i];
        }

        int maxSum = currSum;
        
        for(int i = 1; i <= k; i++) {
            currSum = currSum - res[i - 1] + res[i + k - 1];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};