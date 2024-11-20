class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        
        vector<int> count(3, 0);
        int n = s.length();
        
        // Count characters from the end
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Early validation
        for (int i = 0; i < 3; i++) {
            if (count[i] < k) return -1;
        }
        
        vector<int> window(3, 0);
        int left = 0, maxWindow = 0;
        
        // Sliding window approach
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            
            // Shrink window while any character count exceeds limit
            while (left <= right && (
                window[0] > count[0] - k ||
                window[1] > count[1] - k ||
                window[2] > count[2] - k
            )) {
                window[s[left] - 'a']--;
                left++;
            }
            
            maxWindow = max(maxWindow, right - left + 1);
        }
        
        return n - maxWindow;
    }
};