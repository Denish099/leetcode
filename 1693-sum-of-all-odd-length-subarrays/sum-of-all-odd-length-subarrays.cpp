class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;

        for(int i = 0;i<arr.size();i++){
            int x = 0;
            for(int j = i;j<arr.size();j++){
                x+= arr[j];
                
                if((j - i) % 2 == 0){
                
                    sum+= x;
                }
            }
        }

        return sum;
        
    }
};