class Solution {
    public String lexPalindromicPermutation(String input, String target) {
        String result = "";
        int[] charCount = new int[26];
        
        // Counting frequency of each character in the input string
        for (char ch : input.toCharArray()) {
            charCount[ch - 'a']++;
        }
        
        // Counting how many characters have an odd count
        int oddCount = 0;
        for (int count : charCount) {
            oddCount += (count % 2);
        }
        
        // If there is more than one character with an odd count, we can't form a palindrome
        if (oddCount > 1) {
            return result;
        }
        
        StringBuilder prefix = new StringBuilder();
        int inputLength = input.length();
        
        // Start solving the problem with backtracking
        if (!findPermutation(0, true, prefix, charCount, inputLength, target)) {
            return result;
        }

        // Mirror the prefix to form the full palindrome
        int lastIndex = prefix.length() - 1 - (inputLength % 2);
        while (lastIndex >= 0) {
            prefix.append(prefix.charAt(lastIndex));
            lastIndex--;
        }

        return prefix.toString();
    }

    // Recursive helper method to find lexicographically smallest palindromic permutation
    private boolean findPermutation(int index, boolean isTight, StringBuilder prefix, int[] charCount, int inputLength, String target) {
        if (index == (inputLength + 1) / 2) {
            return comparePrefix(inputLength, prefix.toString(), target);
        }
        
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (isTight) {
                if (ch >= target.charAt(index) &&
                    ((charCount[ch - 'a'] >= 2) ||
                     (charCount[ch - 'a'] >= 1 && (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1)))) {
                    prefix.append(ch);
                    charCount[ch - 'a'] -= (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1) ? 1 : 2;
                    if (findPermutation(index + 1, ch > target.charAt(index) ? false : true, prefix, charCount, inputLength, target)) {
                        return true;
                    }
                    charCount[ch - 'a'] += (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1) ? 1 : 2;
                    prefix.deleteCharAt(prefix.length() - 1);
                }
            } else {
                if ((charCount[ch - 'a'] >= 2) || 
                    (charCount[ch - 'a'] >= 1 && (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1))) {
                    prefix.append(ch);
                    charCount[ch - 'a'] -= (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1) ? 1 : 2;
                    if (findPermutation(index + 1, false, prefix, charCount, inputLength, target)) {
                        return true;
                    }
                    charCount[ch - 'a'] += (inputLength % 2 == 1 && index == (inputLength + 1) / 2 - 1) ? 1 : 2;
                    prefix.deleteCharAt(prefix.length() - 1);
                }
            }
        }
        return false;
    }

    // Helper method to compare the formed half palindrome with the target string
    private boolean comparePrefix(int length, String prefix, String target) {
        int lastIndex = prefix.length() - 1 - (length % 2);
        while (lastIndex >= 0) {
            prefix += prefix.charAt(lastIndex);
            lastIndex--;
        }
        return prefix.compareTo(target) > 0;
    }
}