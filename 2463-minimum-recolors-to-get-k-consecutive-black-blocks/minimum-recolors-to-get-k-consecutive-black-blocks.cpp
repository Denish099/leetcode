class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();

        int cnt = 0;
        for(int i = 0;i<k;i++){
            if(s[i] == 'B'){
                cnt++;
            }
        }

        int i = 0;
        int j = k-1;

        int ans = INT_MAX;

        while(j < n){
            ans = min(ans,k - cnt);

            if(s[i] == 'B'){
                cnt--;
            }

            i++;
            j++;

            if(j < n && s[j] == 'B'){
                cnt++;
            }
        }

        return ans;
        
    }
};