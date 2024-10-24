use std::collections::HashSet;

impl Solution {
    // Main function to find the maximum number of unique substrings
    pub fn max_unique_split(s: String) -> i32 {
        let mut seen: HashSet<String> = HashSet::new();  // Set to store unique substrings
        let mut max_count = 0;  // Variable to store the maximum count of unique substrings
        
        // Call the backtracking function to find the maximum count
        Self::backtrack(&s, 0, &mut seen, 0, &mut max_count);
        
        max_count  // Return the final result
    }

    // Backtracking function to explore all possible splits
    fn backtrack(s: &str, start: usize, seen: &mut HashSet<String>, 
                 count: i32, max_count: &mut i32) {
        // Pruning: If the remaining characters plus current count can't exceed max_count, return
        if count + (s.len() - start) as i32 <= *max_count {
            return;
        }

        // Base case: If we've reached the end of the string
        if start == s.len() {
            *max_count = (*max_count).max(count);  // Update max_count if necessary
            return;
        }

        // Try all possible substrings starting from 'start'
        for end in start + 1..=s.len() {
            let substring = s[start..end].to_string();  // Extract substring
            
            // If the substring is not in the set (i.e., it's unique)
            if !seen.contains(&substring) {
                seen.insert(substring.clone());  // Add the substring to the set
                
                // Recursively call backtrack with updated parameters
                Self::backtrack(s, end, seen, count + 1, max_count);
                
                seen.remove(&substring);  // Remove the substring from the set (backtracking)
            }
        }
    }
}