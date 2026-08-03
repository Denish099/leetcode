class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &arr, int i)
    {
        if(i >= arr.size())
        {
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
        int currValue = arr[i];  
        int currSum = arr[i]; 
        int index = i + 1;
        
        while(index < arr.size() && arr[index] == currValue)
        {
            currSum += arr[i];
            index++;
        }
        
        while(index < arr.size() && arr[index] == currValue + 1)
        {
            index++;
        }
        
      
        
        return dp[i] = max(currSum + solve(arr, index), solve(arr, i + 1));
       
    }
    int deleteAndEarn(vector<int>& arr) {
        int n = arr.size(); 

        dp.resize(n+1,-1);
        
        sort(arr.begin(), arr.end());
        
        return solve(arr, 0);
       
    }
};