func removeSubfolders(folder []string) []string {
    // Sort the folders lexicographically so parent folders come before their subfolders
    sort.Strings(folder)
    
    // Initialize result slice with the first folder
    ans := []string{folder[0]}
    
    // Iterate through remaining folders starting from index 1
    for i := 1; i < len(folder); i++ {
        // Get the last added folder path and add a trailing slash
        lastFolder := ans[len(ans)-1] + "/"
        
        // Check if current folder starts with lastFolder
        // If it doesn't start with lastFolder, then it's not a subfolder
        if !strings.HasPrefix(folder[i], lastFolder) {
            ans = append(ans, folder[i])
        }
    }
    
    return ans
}