class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), [](auto& a, auto& b) {
            if (a[0] != b[0])
                return a[0] > b[0];

            return a[1] < b[1];
        });

        for(auto p:people){
            cout<< p[0] << " "<< p[1]<<endl;
        }

        vector<vector<int>> ans;

        for (auto p : people) {
            ans.insert(ans.begin() + p[1], p);
        }

        return ans;
    }
};