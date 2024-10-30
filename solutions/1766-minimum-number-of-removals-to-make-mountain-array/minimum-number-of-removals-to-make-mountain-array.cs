// Longest Increasing Subsequence (LIS) Solution from both directions

public class Solution {
    // Helper function to calculate LIS lengths for each position
    private List<int> LisLength(int[] v) {
        // Start with first element
        List<int> lis = new List<int> { v[0] };
        // Track LIS length ending at each position
        List<int> lisLen = new List<int>(new int[v.Length]);
        
        for (int i = 0; i < v.Length; i++) {
            lisLen[i] = 1;
        }

        for (int i = 1; i < v.Length; i++) {
            // If current element is larger than last LIS element, extend the sequence
            if (v[i] > lis[lis.Count - 1]) {
                lis.Add(v[i]);
            } else {
                // Replace the smallest element that's >= current element
                // This maintains the potential for longer sequences
                int index = lis.BinarySearch(v[i]);
                if (index < 0) {
                    index = ~index;
                }
                lis[index] = v[i];
            }
            // Store length of LIS up to current position
            lisLen[i] = lis.Count;
        }
        return lisLen;
    }

    public int MinimumMountainRemovals(int[] nums) {
        int n = nums.Length;
        
        // Get LIS lengths from left to right (increasing part)
        List<int> lis = LisLength(nums);
        
        // Get LIS lengths from right to left (decreasing part)
        Array.Reverse(nums);
        List<int> lds = LisLength(nums);
        lds.Reverse();
        Array.Reverse(nums);
        
        int removals = int.MaxValue;
        
        // For each potential peak position
        for (int i = 0; i < n; i++) {
            // Valid mountain needs both sides to have length > 1
            if (lis[i] > 1 && lds[i] > 1) {
                // Calculate removals needed:
                // Total length - (increasing length + decreasing length - 1)
                // -1 because peak is counted twice
                removals = Math.Min(removals, n + 1 - lis[i] - lds[i]);
            }
        }
        
        return removals;
    }
}