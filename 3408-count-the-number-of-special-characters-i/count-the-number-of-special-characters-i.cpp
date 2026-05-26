class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mp;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                mp[word[i]] = 1;
            }
        }
        int count = 0;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                if (mp.find(toupper(word[i])) != mp.end()) {
                    count++;
                    mp.erase(toupper(word[i]));
                }
            }
        }

        return count;
    }
};