class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for(auto ch : n){
            ans = max(ans,ch - 48);

            
        }

        return ans;
        
    }
};