class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int n= nums.size();
        vector<int> prefix;
        for(int i = 0;i<n;i++){
            prefix.push_back(mul);
            mul*=nums[i];
        }
        mul=1;

        vector<int> suffix;

        for(int i = n-1;i>=0;i--){
            suffix.push_back(mul);
            mul*=nums[i];
        }

        reverse(suffix.begin(),suffix.end());

        vector<int> ans;

        for(int i = 0;i<n;i++){
            ans.push_back(suffix[i] * prefix[i]);
        }

        return ans;

    }
};