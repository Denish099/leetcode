class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int qdiff = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qdiff++;
            else
                diff += num[i] - '0';

            if (num[i + n / 2] == '?')
                qdiff--;
            else
                diff -= num[i + n / 2] - '0';
        }

        return 2 * diff != -9 * qdiff;
    }
};