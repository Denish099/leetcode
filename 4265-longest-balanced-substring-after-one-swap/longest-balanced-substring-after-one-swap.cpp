class Solution {
public:
    int longestBalanced(string s) {
        
        int n = s.length();
        int total_ones = 0, total_zeros = 0;
        
        // 1. Count total occurrences of '1' and '0' in the entire string
        for (char c : s) {
            if (c == '1') total_ones++;
            else total_zeros++;
        }
        
        // 2. Maps to store the first and second index where a specific prefix sum was seen
        unordered_map<int, int> first_pos;
        unordered_map<int, int> second_pos;
        
        // Base case: prefix sum 0 mathematically occurs at index -1 (before the string starts)
        first_pos[0] = -1;
        
        int current_sum = 0;
        int max_len = 0;
        
        for (int i = 0; i < n; i++) {
            // Treat '1' as +1 and '0' as -1
            current_sum += (s[i] == '1' ? 1 : -1);
            
            // 3. Record occurrences of prefix sums
            if (first_pos.find(current_sum) == first_pos.end()) {
                first_pos[current_sum] = i;
            } else if (second_pos.find(current_sum) == second_pos.end()) {
                second_pos[current_sum] = i;
            }
            
            // 4. We want to form a substring ending at 'i' with a sum of 0, +2, or -2.
            // Since: current_sum - required_prefix_sum = target
            // Therefore: required_prefix_sum = current_sum - target
            int targets[] = {0, 2, -2};
            
            for (int target : targets) {
                int req_sum = current_sum - target;
                
                // Check if we have seen this required prefix sum before
                if (first_pos.find(req_sum) != first_pos.end()) {
                    int j = first_pos[req_sum];
                    int len = i - j;
                    bool valid = false;
                    
                    // 5. Check if the swap is mathematically possible
                    if (target == 0) {
                        valid = true; // Already balanced, no swap needed
                    } else if (target == 2) {
                        // Substring has sum +2 (two extra '1's). Needs external '0'.
                        int zeros_in_sub = (len - 2) / 2;
                        if (total_zeros > zeros_in_sub) valid = true;
                    } else if (target == -2) {
                        // Substring has sum -2 (two extra '0's). Needs external '1'.
                        int ones_in_sub = (len - 2) / 2;
                        if (total_ones > ones_in_sub) valid = true;
                    }
                    
                    // 6. Update max_len
                    if (valid) {
                        max_len = max(max_len, len);
                    } else if (second_pos.find(req_sum) != second_pos.end()) {
                        // If the first occurrence trapped all needed characters inside,
                        // the second occurrence is guaranteed to leave one outside.
                        int j2 = second_pos[req_sum];
                        max_len = max(max_len, i - j2);
                    }
                }
            }
        }
        
        return max_len;
    }
};