class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        if (n == 0) {
            return 0;
        }

        stack<int> st;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int x = arr[i];

            while(!st.empty() && st.top() > arr[i]){
                x = max(x,st.top());
                st.pop();
            }

            st.push(x);
        }

        return st.size();
    }
};