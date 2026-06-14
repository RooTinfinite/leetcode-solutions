import java.util.Arrays;

class Solution {
    public int minOperations(String s) {
        int n = s.length();
        
        // Prepare s1 and s2 as char arrays to allow sorting
        char[] s1 = s.toCharArray();
        char[] s2 = s.toCharArray();

        // Sort substring [0, n-2] (equivalent to s1.begin(), s1.begin() + n-1)
        Arrays.sort(s1, 0, n - 1);
        
        // Sort substring [1, n-1] (equivalent to s2.begin() + 1, s2.end())
        Arrays.sort(s2, 1, n);

        // Case 0: Is the original string already sorted?
        if (isSorted(s.toCharArray())) return 0;

        // Case 1: Does sorting one substring fix the whole string?
        if (isSorted(s1) || isSorted(s2)) return 1;

        // Case 2: Using your specific character comparison logic
        // s1[n-1] is the original last character; s1[0] is the new smallest of the prefix
        if (s1[n - 1] >= s1[0]) return 2;
        if (s2[0] <= s2[n - 1]) return 2;

        // Case 3: For strings longer than 2
        if (n > 2) return 3;

        // Otherwise impossible
        return -1;
    }

    // Helper to check if a char array is sorted
    private boolean isSorted(char[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
}