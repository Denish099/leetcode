class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;
        
        for(string s : nums){
            int val = stoi(s, 0, 2);
            st.insert(val);
        }
        
        for(int i = 0; i < (1<<n); i++){
            if(st.find(i) == st.end()){
                
                string ans = "";
                
                for(int j = n-1; j >= 0; j--){
                    if(i & (1<<j)) ans += '1';
                    else ans += '0';
                }
                
                return ans;
            }
        }
        
        return "";
    }
};