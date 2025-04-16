class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long prefixSum = 0;
        long long longestSubarray = 0;
        unordered_map<long long, long long> indices;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if (prefixSum == k) {
                longestSubarray = i + 1;
            }
            
            // If any subarray seen so far sums to k, then
            // update the length of the longest_subarray. 
            if (indices.find((long long)prefixSum - k) != indices.end()) {
                longestSubarray = max(longestSubarray, (long long)i - indices[prefixSum - k]);
            }

            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (indices.find(prefixSum) == indices.end()) {
                indices[prefixSum] = i;
            }
        }
        
        return longestSubarray;
    }
};