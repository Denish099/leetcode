class Solution {
    vector<int> segTree;

    void update(int start, int end, int index, int pos, int value) {
        if (start == end) {
            segTree[index] = value;
            return;
        }
        int mid = start + (end - start) / 2;
        if (pos <= mid) {
            update(start, mid, 2 * index, pos, value);
        } else {
            update(mid + 1, end, 2 * index + 1, pos, value);
        }
        segTree[index] = max(segTree[2 * index], segTree[2 * index + 1]);
    }

    int query(int start, int end, int index, int L, int R) {
        if (start >= L && end <= R) {
            return segTree[index];
        }
        if (start > R || end < L) {
            return 0; 
        }
        int mid = start + (end - start) / 2;
        int leftAns = query(start, mid, 2 * index, L, R);
        int rightAns = query(mid + 1, end, 2 * index + 1, L, R);
        
        return max(leftAns, rightAns);
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        segTree.assign(4 * (max_x + 1), 0);
        
        set<int> obstacles;
        obstacles.insert(0); 
        
        vector<bool> ans;
        
        for (const auto& q : queries) {
            int type = q[0];
            int x = q[1];
            
            if (type == 1) { 
                auto it = obstacles.lower_bound(x);
                int prev_obs = *prev(it);
                
                update(0, max_x, 1, x, x - prev_obs);
                
                if (it != obstacles.end()) {
                    int next_obs = *it;
                    update(0, max_x, 1, next_obs, next_obs - x);
                }
                
                obstacles.insert(x);
            } 
            else if (type == 2) { 
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                int last_obs = *prev(it);
                
                int max_gap = query(0, max_x, 1, 0, last_obs);
                
                int tail_gap = x - last_obs;
                
                if (max(max_gap, tail_gap) >= sz) {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
        }
        
        return ans;
    }
};