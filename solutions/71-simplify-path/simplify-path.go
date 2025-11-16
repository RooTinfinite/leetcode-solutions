func simplifyPath(path string) string {
    // Split string into portions
    portions := strings.Split(path, "/")
    // Initialize a 'stack'
    stack := []string{}
    // For each portion...
    for _, portion := range portions {
        // If portion is "..", pop the stack unless it's empty
        if portion == ".." {
            if len(stack) > 0 {
                stack = stack[:len(stack)-1]
            }
        } else if portion != "." && len(portion) > 0 {
            // If portion isn't "." and not empty, append to stack
            stack = append(stack, portion)
        }
    }
    // Concatenate portions to simple path and return
    return "/" + strings.Join(stack, "/")
}