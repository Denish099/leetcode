class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);

        for(char c : s) {
            arr[c - 'a']++;
        }

        string left = "";
        string mid = "";

        for(int i = 0; i < 26; i++) {
            if(arr[i] % 2 == 1) {
                mid += (char)(i + 'a'); 
            }

            left += string(arr[i] / 2, (char)(i + 'a'));
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};