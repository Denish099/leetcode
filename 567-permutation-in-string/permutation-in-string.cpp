class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m1;
        map<char, int> m2;
        int n = s1.length();

        for (int i = 0; i < n; i++) {
            m1[s1[i]]++;
            
        }
        for (int i = 0; i < n && i < s2.size(); i++) {
            m2[s2[i]]++;  
        }

        if (m1 == m2) {
            return true;
        }

        for (int i = n; i < s2.length(); i++) {
            if (m2[s2[i - n]] == 1) {
                m2.erase(s2[i - n]);
            } else {
                m2[s2[i - n]]--;
            }
            m2[s2[i]]++;

            if(m1 == m2){
                return true;
            }
        }

        return false;
    }
};