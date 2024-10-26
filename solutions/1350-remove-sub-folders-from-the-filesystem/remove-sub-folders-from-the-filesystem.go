func removeSubfolders(folder []string) []string {
    // Sort the folders lexicographically
    sort.Strings(folder)
    
    // Initialize result slice with the first folder
    ans := []string{folder[0]}
    
    // Iterate through remaining folders
    for i := 1; i < len(folder); i++ {
        lastFolder := ans[len(ans)-1] + "/"
        
        // Check if current folder is not a subfolder of the last added folder
        if !strings.HasPrefix(folder[i], lastFolder) {
            ans = append(ans, folder[i])
        }
    }
    
    return ans
}