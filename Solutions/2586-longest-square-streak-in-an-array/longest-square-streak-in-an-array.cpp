class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Convert nums to a sorted set to remove duplicates and have ordered numbers
        set<long long> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }
        
        // Track the maximum streak length found
        int max_length = 0;
        
        // Iterate through each number in sorted order
        for (long long num : num_set) {
            // Initialize streak length for current number
            int length = 0;
            // Start with current number
            long long current = num;
            
            // Keep squaring the number while it exists in our set
            while (num_set.find(current) != num_set.end()) {
                length++;
                if (current > 100000) break; // Prevent overflow
                current = current * current;
            }
            
            // Only update max_length if we found a streak of length > 1
            if (length > 1) {
                max_length = max(max_length, length);
            }
        }
        
        // Return max_length if we found a valid streak, otherwise return -1
        return max_length > 1 ? max_length : -1;
    }
};