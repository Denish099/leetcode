class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> arr;
        int x = target[0];
        int y = target[1];
        int z = target[2];
        bool flagX = false;
        bool flagY = false;
        bool flagZ = false;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] <= x && triplets[i][1] <= y &&
                triplets[i][2] <= z) {
                arr.push_back({triplets[i][0], triplets[i][1], triplets[i][2]});

                if (triplets[i][0] == x) {
                    flagX = true;
                }
                if (triplets[i][1] == y) {
                    flagY = true;
                }
                if (triplets[i][2] == z) {
                    flagZ = true;
                }
            }
        }


        if(!flagX || !flagY || !flagZ){
            return false;
        }

        return true;
    }
};