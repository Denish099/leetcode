class Solution {
public:
    int arr[1001][1001];
    bool helper(string s,int i,int j){
        if(i >= j){
            return 1;
        }

        if(arr[i][j] != -1){
            return arr[i][j];
        }

        if(s[i] == s[j]){
            return arr[i][j] = helper(s,i+1,j-1);
        }

        return arr[i][j] = 0;
    }
    int countSubstrings(string s) {
        memset(arr,-1,sizeof(arr));
        int n = s.size();
        int count = 0;

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(helper(s,i,j))count++;
            }
        }
        return count;
    }
};