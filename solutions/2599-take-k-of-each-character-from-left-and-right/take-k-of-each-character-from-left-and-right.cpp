class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> charCount(3, 0);
        int length = s.length();
        
        int left;
        for (left = 0; left < length; left++) {
            charCount[s[left] - 'a']++;
            if (isValidCount(charCount, k)) {
                break;
            }
        }
        
        if (left == length) {
            return -1;
        }
        
        int currentCount = left + 1;
        int minCount = currentCount;
        int right = length - 1;
        
        while (left >= 0) {
            int currentChar = s[left] - 'a';
            
            if (charCount[currentChar] == k) {
                while (s[left] != s[right]) {
                    charCount[s[right] - 'a']++;
                    right--;
                    currentCount++;
                }
                right--;
            } else {
                charCount[currentChar]--;
                currentCount--;
                minCount = min(currentCount, minCount);
            }
            left--;
        }
        
        return minCount;
    }
    
private:
    bool isValidCount(const vector<int>& count, int k) {
        return count[0] >= k && count[1] >= k && count[2] >= k;
    }
};
