class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int countA = 0, countB = 0, countC = 0;
        
        // Count total occurrences of each character
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') countA++;
            if(s[i] == 'b') countB++;
            if(s[i] == 'c') countC++;
        }
        
        // Check if it's possible to get k occurrences of each character
        if(countA < k || countB < k || countC < k) {
            return -1;
        }
        
        int minLength = n;
        int right = n - 1;
        
        // Try different windows by moving left pointer
        for(int left = n - 1; left >= 0; left--) {
            // Remove character at left pointer from counts
            if(s[left] == 'a') countA--;
            if(s[left] == 'b') countB--;
            if(s[left] == 'c') countC--;
            
            // Adjust right pointer until we have k of each character
            while(countA < k || countB < k || countC < k) {
                if(s[right] == 'a') countA++;
                if(s[right] == 'b') countB++;
                if(s[right] == 'c') countC++;
                right--;
            }
            
            // Update minimum length required
            minLength = min(minLength, left + n - 1 - right);
        }
        
        return minLength;
    }
};