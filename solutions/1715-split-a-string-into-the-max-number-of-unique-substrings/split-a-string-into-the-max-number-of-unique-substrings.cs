using System;
using System.Collections.Generic;

public class Solution {
    // Main function to find the maximum number of unique substrings
    public int MaxUniqueSplit(string s) {
        HashSet<string> seen = new HashSet<string>();  // Set to store unique substrings
        int maxCount = 0;  // Variable to store the maximum count of unique substrings
        
        // Call the backtracking function to find the maximum count
        Backtrack(s, 0, seen, 0, ref maxCount);
        
        return maxCount;  // Return the final result
    }

    // Backtracking function to explore all possible splits
    private void Backtrack(string s, int start, HashSet<string> seen,
                           int count, ref int maxCount) {
        // Pruning: If the remaining characters plus current count can't exceed maxCount, return
        if (count + (s.Length - start) <= maxCount) return;

        // Base case: If we've reached the end of the string
        if (start == s.Length) {
            maxCount = Math.Max(maxCount, count);  // Update maxCount if necessary
            return;
        }

        // Try all possible substrings starting from 'start'
        for (int end = start + 1; end <= s.Length; ++end) {
            string substring = s.Substring(start, end - start);  // Extract substring
            
            // If the substring is not in the set (i.e., it's unique)
            if (!seen.Contains(substring)) {
                seen.Add(substring);  // Add the substring to the set
                
                // Recursively call Backtrack with updated parameters
                Backtrack(s, end, seen, count + 1, ref maxCount);
                
                seen.Remove(substring);  // Remove the substring from the set (backtracking)
            }
        }
    }
}