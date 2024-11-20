class Solution {
public:
    int takeCharacters(string_view s, int k) {
        if (k == 0) return 0;
        
        array<int, 3> count{};
        const int n = s.length();
        
        // Count total frequencies
        const char* ptr = s.data();
        const char* end = ptr + n;
        while (ptr < end) {
            count[*ptr++ - 'a']++;
        }
        
        if (count[0] < k || count[1] < k || count[2] < k) return -1;
        
        array<int, 3> window{};
        int left = 0, maxWindow = 0;
        
        for (int right = 0; right < n; ++right) {
            ++window[s[right] - 'a'];
            
            while (left <= right && (
                window[0] > count[0] - k ||
                window[1] > count[1] - k ||
                window[2] > count[2] - k
            )) {
                --window[s[left] - 'a'];
                ++left;
            }
            
            maxWindow = max(maxWindow, right - left + 1);
        }
        
        return n - maxWindow;
    }
};