class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indexMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        
        for (const auto& pair : indexMap) {
            const vector<int>& indices = pair.second;
            
            if (indices.size() < 3) {
                continue;
            }
            
          
            for (size_t h = 0; h < indices.size() - 2; ++h) {
                int dist = 2 * (indices[h+2] - indices[h]);
                minDist = min(minDist, dist);
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};