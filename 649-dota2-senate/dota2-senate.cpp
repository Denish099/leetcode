class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> R;
        queue<int> D;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                R.push(i);
            } else {
                D.push(i);
            }
        }

        while (!R.empty() && !D.empty()) {
            int r = R.front();
            int d = D.front();

            R.pop();
            D.pop();

            if (r < d) {
                R.push(r + n);
            } else {
                D.push(d + n);
            }
        }

        if (R.empty()) {
            return "Dire";
        }

        return "Radiant";
    }
};