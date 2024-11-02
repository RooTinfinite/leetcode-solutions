class Solution {
public:
    // Function to find two numbers in array that add up to target
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash table to store number->index mapping
        unordered_map<int, int> ht;
        
        // Variable to store current number
        int tmp;

        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            tmp = nums[i];
            
            // Check if complement (target - current number) exists in hash table
            if (ht.find(target-tmp) != ht.end()) {
                // If found, return indices of both numbers
                return {ht[target-tmp], i};
            }
            
            // Store current number and its index in hash table
            ht[tmp] = i;
        }
        
        // Return empty vector if no solution found
        return {};
    }
};