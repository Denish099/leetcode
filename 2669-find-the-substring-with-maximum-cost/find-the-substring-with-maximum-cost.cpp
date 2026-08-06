class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        for(int i = 0;i<chars.size();i++){
            mp[chars[i]] = vals[i];
        }

        vector<int> arr;
        for(int i = 0;i<s.size();i++){
            if(mp.find(s[i])  != mp.end()){
                arr.push_back(mp[s[i]]);
            }else{
                arr.push_back(s[i] - 'a' + 1);
            }
        }

        int ans = 0;
        int sum = 0;

        for(int i = 0;i<arr.size();i++){
            if(sum < 0){
                sum = 0;
            }

            sum += arr[i];
            ans = max(ans,sum);
        }

        return ans;

      
        
    }
};