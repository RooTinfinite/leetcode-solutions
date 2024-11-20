class Solution {
    public int takeCharacters(String s, int k) {
        // Count frequencies of characters a, b, c
        int[] charCount = new int[3];
        char[] chars = s.toCharArray();
        int length = chars.length;
        
        // Find first valid position from left
        int left;
        for (left = 0; left < length; left++) {
            charCount[chars[left] - 'a']++;
            if (isValidCount(charCount, k)) {
                break;
            }
        }
        
        // If we couldn't find valid count
        if (left == length) {
            return -1;
        }
        
        // Initialize variables for sliding window
        int currentCount = left + 1;
        int minCount = currentCount;
        int right = length - 1;
        
        // Slide window to find minimum length
        while (left >= 0) {
            int currentChar = chars[left] - 'a';
            
            if (charCount[currentChar] == k) {
                // Move right pointer until matching character found
                while (chars[left] != chars[right]) {
                    charCount[chars[right] - 'a']++;
                    right--;
                    currentCount++;
                }
                right--;
            } else {
                charCount[currentChar]--;
                currentCount--;
                minCount = Math.min(currentCount, minCount);
            }
            left--;
        }
        
        return minCount;
    }
    
    private boolean isValidCount(int[] count, int k) {
        return count[0] >= k && count[1] >= k && count[2] >= k;
    }
}
