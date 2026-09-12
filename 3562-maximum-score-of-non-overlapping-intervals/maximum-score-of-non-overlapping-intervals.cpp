class Solution {
public:

    struct Result {
        long long score = 0;
        array<int, 4> id;
        int cnt = 0;
    };

    int n;


    vector<array<Result, 5>> dp;


    bool better(Result &a, Result &b) {

        if (a.score != b.score)
            return a.score > b.score;

        for (int i = 0; i < min(a.cnt, b.cnt); i++) {
            if (a.id[i] != b.id[i])
                return a.id[i] < b.id[i];
        }

        return a.cnt < b.cnt;
    }


    Result add(Result x, int index) {

        int pos = x.cnt;

        while (pos > 0 && x.id[pos - 1] > index) {
            x.id[pos] = x.id[pos - 1];
            pos--;
        }

        x.id[pos] = index;
        x.cnt++;

        return x;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }


        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }


        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] =
                upper_bound(
                    starts.begin(),
                    starts.end(),
                    a[i][1]
                ) - starts.begin();
        }

        dp.resize(n + 1);


        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                Result skip = dp[i + 1][k];


                Result take = dp[next[i]][k - 1];

                take.score += a[i][2];

                take = add(take, a[i][3]);


                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        Result ans = dp[0][4];

        vector<int> res;

        for (int i = 0; i < ans.cnt; i++)
            res.push_back(ans.id[i]);

        return res;
    }
};