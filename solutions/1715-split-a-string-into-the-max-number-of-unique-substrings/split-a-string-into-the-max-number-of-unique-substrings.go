func maxUniqueSplit(s string) int {
    // Initialize the answer to 1 (minimum possible split)
    ans := 1
    // Create a map to keep track of visited substrings
    vis := map[string]bool{}

    // Declare a recursive function dfs
    var dfs func(i, t int)
    dfs = func(i, t int) {
        // Base case: if we've reached the end of the string
        if i >= len(s) {
            // Update the answer with the maximum of current answer and current split count
            ans = max(ans, t)
            return
        }
        
        // Try all possible substrings starting from index i
        for j := i + 1; j <= len(s); j++ {
            // Extract the substring
            x := s[i:j]
            // If this substring hasn't been used before
            if !vis[x] {
                // Mark it as visited
                vis[x] = true
                // Recursively call dfs with the next starting index and incremented split count
                dfs(j, t+1)
                // Backtrack: mark the substring as unvisited for other possibilities
                vis[x] = false
            }
        }
    }

    // Start the DFS from index 0 with initial split count 0
    dfs(0, 0)
    
    // Return the maximum number of unique splits found
    return ans
}