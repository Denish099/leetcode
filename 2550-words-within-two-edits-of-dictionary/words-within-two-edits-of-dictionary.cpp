class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(int i = 0;i<queries.size();i++){
            int count = INT_MAX;
            for(int j = 0;j<dictionary.size();j++){
                int cnt = 0;
                for(int k = 0;k<queries[i].length();k++){
                    if(queries[i][k] != dictionary[j][k]){
                        cnt++;
                    }
                }
                count = min(count,cnt);
            }
            if(count <= 2){
                ans.push_back(queries[i]);
            }
        }

        return ans;
        
    }
};