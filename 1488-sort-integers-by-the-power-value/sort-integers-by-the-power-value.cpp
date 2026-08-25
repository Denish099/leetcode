class Solution {
public:

    int power(int n) {
        int count = 0;

        while (n != 1) {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = 3 * n + 1;

            count++;
        }

        return count;
    }

    int getKth(int lo, int hi, int k) {

        vector<pair<int, int>> arr;

        for (int i = lo; i <= hi; i++) {
            arr.push_back({power(i), i});
        }

        sort(arr.begin(), arr.end());

        return arr[k - 1].second;
    }
};