// Force O3 optimization and disable address sanitizer for maximum speed
__attribute__((no_sanitize("address"), optimize("O3")))
int minimumDeletions(char* s) {
    int b_count = 0;
    int deletions = 0;
    
    // Iterate using pointer arithmetic (faster than array indexing s[i])
    while (*s) {
        if (*s == 'b') {
            b_count++;
        } else {
            // Found 'a'. We calculate the minimum deletions required so far:
            // Option 1: Delete this 'a' (current deletions + 1)
            // Option 2: Delete all preceding 'b's (b_count)
            // We update 'deletions' to the minimum of these two options.
            if (deletions + 1 < b_count) {
                deletions++;
            } else {
                deletions = b_count;
            }
        }
        s++; // Move pointer to the next character
    }
    
    return deletions;
}