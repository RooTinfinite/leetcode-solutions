class Solution {
    public long validSubstringCount(String source, String target) {

        int[] targetFreq = new int[26];
        for (int i = 0; i < target.length(); i++) {
            char c = target.charAt(i);
            targetFreq[c - 'a']++;
        }

        int start = 0;
        int[] currentFreq = new int[26];
        long validSubstrings = 0;
        for (int end = 0; end < source.length(); end++) {

            int charIndex = source.charAt(end) - 'a';
            currentFreq[charIndex]++;

            boolean isValid = true;
            for (int j = 0; j < 26; j++) {
                if (targetFreq[j] > currentFreq[j]) {
                    isValid = false;
                    break;
                }
            }

            while (isValid) {
                validSubstrings += (long) (source.length() - end);
                charIndex = source.charAt(start) - 'a';
                currentFreq[charIndex]--;
                start++;

                isValid = true;
                for (int j = 0; j < 26; j++) {
                    if (targetFreq[j] > currentFreq[j]) {
                        isValid = false;
                        break;
                    }
                }
            }
        }
        return validSubstrings;
    }
}