class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rSize = heights.size();
        int cSize = heights[0].size();
        
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        
        vector<vector<int>> distance(rSize, vector<int>(cSize, INT_MAX));
        
        distance[0][0] = 0;
        pq.push({0, {0,0}});
        
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        
        while(!pq.empty()) {
            
            auto [effort, coords] = pq.top();
            auto [x, y] = coords;
            pq.pop();
            
            if(x == rSize-1 && y == cSize-1)
                return effort;
            
            for(int i = 0; i < 4; i++) {
                
                int r = x + dr[i];
                int c = y + dc[i];
                
                if(r >= 0 && c >= 0 && r < rSize && c < cSize) {
                    
                    int newEffort = max(
                        effort,
                        abs(heights[x][y] - heights[r][c])
                    );
                    
                    if(newEffort < distance[r][c]) {
                        distance[r][c] = newEffort;
                        pq.push({newEffort, {r, c}});
                    }
                }
            }
        }
        
        return 0;
    }
};
