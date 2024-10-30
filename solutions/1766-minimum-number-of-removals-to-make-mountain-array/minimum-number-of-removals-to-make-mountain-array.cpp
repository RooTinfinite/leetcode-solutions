class Solution {
public:
// Longest Increasing Subsequence (LIS) Solution from both directions

    // Helper function to calculate LIS lengths for each position
    vector<int> lisLength(vector<int>& v){
        // Start with first element
        vector<int> lis = {v[0]};
        // Track LIS length ending at each position
        vector<int> lisLen(v.size(), 1);

        for(int i = 1 ; i < v.size() ; i++){
            // If current element is larger than last LIS element, extend the sequence
            if(v[i] > lis.back()){
                lis.push_back(v[i]);
            } else {
                // Replace the smallest element that's >= current element
                // This maintains the potential for longer sequences
                int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[index] = v[i];
            }
            // Store length of LIS up to current position
            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        // Get LIS lengths from left to right (increasing part)
        vector<int> lis = lisLength(nums);
        
        // Get LIS lengths from right to left (decreasing part)
        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLength(nums);
        reverse(lds.begin(), lds.end());
        
        int removals = INT_MAX;
        
        // For each potential peak position
        for(int i = 0 ; i < n ; i++){
            // Valid mountain needs both sides to have length > 1
            if(lis[i] > 1 && lds[i] > 1){
                // Calculate removals needed:
                // Total length - (increasing length + decreasing length - 1)
                // -1 because peak is counted twice
                removals = min(removals, n + 1 - lis[i] - lds[i]);
            }
        }
        
        return removals;
    }
};